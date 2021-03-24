// SimulateManager.h
// @Author: Kray Nguyen
// 2/26/2021
// Class that generate and insert bot and legitimate calls to the PQ, then process
// the PQ using the event loop data flow presented on the assignment page

#ifndef _SM_
#define _SM_
#include <iostream>
#include "PriorityQueue.h"
#include <string>
#include <queue>
#include <vector>


using namespace std;

class SimulateManager{

public:
    SimulateManager();

    // @param {int} - c: number of call takers
    // @param {int} - ave_calls: average calls per hour
    // @param {int} - ave_serv: average service time 
    // @param {int} - bots: number of bots
    // @pre: param inputs are valid
    // @post: SimulateManager is created
    // @return: none
    // @function called: none
    SimulateManager(int c, int ave_calls, int ave_serv, int bots);

    // @pre: the PQ event list, queue call line, and other important variables are initialized
    // @post: bot events are created and added to the PQ
    // @return: none
    // @function called: PQ.enqueue(), event.setArrival(), event.setEventType()
    void generateBot();

    // @pre: the PQ event list, queue call line, and other important variables are initialized
    // @post: legitimate call events are created and added to the PQ
    // @return: none
    // @function called: PQ.enqueue(), event.setArrival(), event.setEventType()
    void generateLegitCalls();

    // @pre: the PQ event list are filled with bot and legit call events
    // @post: PQ is empty
    // @return: none
    // @function called: PQ.enqueue(), event.setArrival(), event.setEventType(), event.setDeparture()
    // freeCallTaker(), callTakerIsFree()
    void process();

    // @pre: the PQ is processed
    // @post: averate total service time printed to console
    // @return: none
    // @function called: calculateOutput();
    void printStats();

    
    // @pre: the PQ is initiliazed
    // @post: min-heap representation of the PQ is displayed
    // @return: none
    // @function called: none
    void showPQ();

    
private:
    queue<Event> call_line;
    PriorityQueue event_list;
    
    // input variables
    int call_takers, average_calls_ph, average_service_time, num_bots;

    // lambda variables for poisson distribution
    double lambda_c, lambda_s;
    int bot_arrival_time, legit_arrival_time, legit_service_time, legit_departure_time;
    
    // variables to keep track of time
    int legit_total_service_time, current_time;
    int total_num_events, legit_processed;

    // @pre: call_takers are initialized
    // @post: call takers increment by 1
    // @return: none
    // @function called: none
    void freeCallTaker();

    // @pre: legit_total_service_time and legit_processed are valid
    // @post: none
    // @return: average total sevice time
    // @function called: none
    int calculateOutput();

    // @pre: call_takers are initialized
    // @post: none
    // @return: true if call_takers > 0
    // @function called: none
    bool callTakersIsFree();

    // @pre: call_takers are initialized
    // @post: call takers decrement by 1
    // @return: none
    // @function called: none
    void occupyCallTakers();
    
};

#endif