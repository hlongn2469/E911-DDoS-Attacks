// SimulateManager.cpp
// @Author: Kray Nguyen
// 2/26/2021
// Class that generate and insert bot and legitimate calls to the PQ, then process
// the PQ using the event loop data flow presented on the assignment page
#include "SimulateManager.h"
#include <random>
#include <cmath>                   



SimulateManager:: SimulateManager(){

}

// @param {int} - c: number of call takers
// @param {int} - ave_calls: average calls per hour
// @param {int} - ave_serv: average service time 
// @param {int} - bots: number of bots
// @pre: param inputs are valid
// @post: SimulateManager is created
// @return: none
// @function called: none

SimulateManager::SimulateManager(int c, int ave_calls, int ave_serv, int bots){
    // set important values
    call_takers = c;
    average_calls_ph = ave_calls;
    average_service_time = ave_serv;
    num_bots = bots;
    total_num_events = 0;
    legit_total_service_time = 0;
    legit_processed = 0;
    // calculate lambda_c aka average call per sec
    lambda_c = ((double)average_calls_ph) / 3600.0;
    lambda_s = ((double)1.0) / average_service_time; 
    
}

// @pre: the PQ event list are filled with bot and legit call events
// @post: PQ is empty
// @return: none
// @function called: PQ.enqueue(), event.setArrival(), event.setEventType(), event.setDeparture()
// freeCallTaker(), callTakerIsFree()
void SimulateManager::process(){
    // while pq is not empty
    current_time = 0;

    //cout << event_list << endl;

    while(!event_list.isEmpty() && current_time == event_list.peek().getCompareTime()){
        
        
        // dequeue                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
        Event current = event_list.dequeue();
        
        // if the event is call-placed
        if(current.getEventType() == "call-placed"){
            
            // if call taker is free
            if(callTakersIsFree()){
                occupyCallTakers();
               
                // set the event as service-ended 
                current.setEventType("service-ended");

               
                // no need to wait if the event is call placed AND the call taker is available in the first place
                // wait time = 0 by default

                // compute departure time
                int departure = current.getArrival() + current.getServiceTime();
                current.setDeparture(departure);
                // enqueue the event to PQ
                event_list.enqueue(current);

                current_time = event_list.peek().getCompareTime();
   

            // if call takers are all busy
            } else {
                // needs to set wait time + departure later
                // put the event on waiting list
                call_line.push(current);
                current_time = event_list.peek().getCompareTime();
            }

        // if the event is service-ended
        } else if(current.getEventType() == "service-ended"){
            // Event printEvent = event_list.dequeue();


            // if legit event, compute the current event's total service time
            if(!current.isBotCall()){
                int total_service_time = current.getTotalTime();
                // add current total service time to the program's total service time
                legit_total_service_time += total_service_time;
                legit_processed++;
            }

            // free call taker
            freeCallTaker();

            // if the waiting line is not empty and the call taker is free
            if(!call_line.empty()){
                
                // get event from the waiting list, then enqueue to PQ as service ended event
                Event wait_list_event = call_line.front();
                call_line.pop();
                occupyCallTakers();
                // set the wait time for the dequeue event
                int waiting_time = current_time - wait_list_event.getArrival();
                
                wait_list_event.setWaitTime(waiting_time);
                
                // set type as service ended
                wait_list_event.setEventType("service-ended");
                wait_list_event.setDeparture( wait_list_event.getArrival() +  wait_list_event.getServiceTime() +  wait_list_event.getWaitTime());

                // enqueue to PQ
                event_list.enqueue(wait_list_event);
            }

            if (event_list.getSize()!= 0)
            {
                current_time = event_list.peek().getCompareTime();
            }
        }
        
    }
}

// @pre: call_takers are initialized
// @post: call takers increment by 1
// @return: none
// @function called: none
void SimulateManager::freeCallTaker(){
    //call_takers_line.at(event.getCallTakerIndex()) = true;
    call_takers++;
}

// @pre: call_takers are initialized
// @post: call takers decrement by 1
// @return: none
// @function called: none
void SimulateManager::occupyCallTakers(){
    //call_takers_line.at(event.getCallTakerIndex()) = true;
    call_takers--;
}

// @pre: call_takers are initialized
// @post: none
// @return: true if call_takers > 0
// @function called: none
bool SimulateManager::callTakersIsFree(){
    return call_takers > 0;
}

// @pre: legit_total_service_time and legit_processed are valid
// @post: none
// @return: average total sevice time
// @function called: none
int SimulateManager::calculateOutput(){
    return legit_total_service_time / legit_processed;
}

// @pre: the PQ event list, queue call line, and other important variables are initialized
// @post: legitimate call events are created and added to the PQ
// @return: none
// @function called: PQ.enqueue(), event.setArrival(), event.setEventType()
void SimulateManager::generateLegitCalls(){
    default_random_engine generator1;    
    default_random_engine generator2;    
    exponential_distribution<double> expDist1(lambda_c); // distribution; lambda is rate
    exponential_distribution<double> expDist2(lambda_s);

    int prev_call_time = 0;
    int theInterval = 0;
    int legit_service_time = 0;

    while(prev_call_time < 3600)
    {
        theInterval = int(ceil(expDist1(generator1))); // returns double from exponential distribution
        
        // get service time
        legit_service_time = int(ceil(expDist2(generator2)));

        // if the PQ is empty, set arrival time to 0
        if (event_list.isEmpty())
        {
            Event new_event(0, legit_service_time, false, "call-placed", 0, 0);
            new_event.setArrival(0);
      
            new_event.setEventType("call-placed");

 
            event_list.enqueue(new_event);
            total_num_events++;
        
        } 

        // else, get arrival time by previous arrival time + the interval
        else 
        {
            legit_arrival_time = prev_call_time + theInterval;

            // create legit event
            Event new_event(legit_arrival_time, legit_service_time, false, "call-placed", 0, 0);
            new_event.setArrival(legit_arrival_time);
       
            new_event.setEventType("call-placed");

            // add to PQ
            event_list.enqueue(new_event);
            total_num_events++;
            
            // update prev_call_time
            prev_call_time = legit_arrival_time;
        }
    }
}

// @pre: the PQ event list, queue call line, and other important variables are initialized
// @post: bot events are created and added to the PQ
// @return: none
// @function called: PQ.enqueue(), event.setArrival(), event.setEventType()
void SimulateManager::generateBot(){
    default_random_engine generator;    
    // generate random based on the num_bots input
    for(int i = 0; i < num_bots; i++){
        uniform_int_distribution<int> uniform(1, 3600); 
        bot_arrival_time = uniform(generator); 

        // create new event 
        Event new_event(bot_arrival_time, 6, true, "call-placed", 0, 0);
        new_event.setArrival(bot_arrival_time);
       
        new_event.setEventType("call-placed");
       
        // add to PQ
        event_list.enqueue(new_event);
        total_num_events++;
    }
}

void SimulateManager::showPQ(){
    cout << event_list << endl;
    //cout << event_list.getSize() << endl;
}

void SimulateManager::printStats(){
    int result = calculateOutput();
    cout << "Average total service time: " << result << endl;
}


