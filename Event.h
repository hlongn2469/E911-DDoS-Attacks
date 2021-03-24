// Event.h
// @Author: Kray Nguyen
// 2/26/2021
// This class store time tracking variables such as arrival, departure, wait, and service time 
// of an event
#ifndef _EV_
#define _EV_
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Event {
    // @pre: printing variables are valid
    // @post: display arrival, compare, service, wait, and total service time to output
    // @return: none
    // @function called: none
    friend ostream& operator<<(ostream & the_stream, const Event& rhs){
        the_stream << "Arrival: " << rhs.arrival_time << " compare: " << rhs.compare_time << "  " << rhs.event_type
        << " service: " << rhs.service_time << " wait: " << rhs.wait_time << " Departure: " << rhs.departure_time  <<" total: "
        << rhs.total_service_time << endl ;
        //the_stream << "compare time: " <<rhs.compare_time << endl;

        return the_stream;
    }
public:
    // @pre: class is instantiated
    // @post: wait time is set to 0
    // @return: none
    // @function called: none
    Event();

    // @pre: other is a valid event
    // @post: deep copy object created
    // @return: none
    // @function called: none
    Event(const Event& other);

    // @pre: valid inputs
    // @post: variables are setted through parameterized constructor
    // @return: none
    // @function called: none
    Event(int a, int s, bool bot, string type, int d, int w);

    // @pre: event_type is initialized
    // @post: none
    // @return: string event_type
    // @function called: none
    string getEventType();

    // @pre: arrival_time is initialized
    // @post: none
    // @return: arrival_time
    // @function called: none
    int getArrival();

    // @pre: departure_time is initialized
    // @post: none
    // @return: departure_time
    // @function called: none
    int getDeparture();

    // @pre: service_time is initialized
    // @post: none
    // @return: service_time
    // @function called: none
    int getServiceTime();

    // @pre: wait_time is initialized
    // @post: none
    // @return: string wait_time
    // @function called: none
    int getWaitTime();

    // @pre: CallTakerIndex is initialized
    // @post: none
    // @return: CallTakerIndex
    // @function called: none
    int getCallTakerIndex();

    // @pre: TotalTime is initialized
    // @post: none
    // @return: TotalTime
    // @function called: none
    int getTotalTime();

    // @pre: CompareTime is initialized
    // @post: none
    // @return: CompareTime
    // @function called: none
    int getCompareTime();

    // @param: {int} - time: time to set
    // @pre: time is initialized
    // @post: compare_time is set
    // @return: true
    // @function called: none
    bool setCompareTime(int time);

    // @param: {int} - time: time to set
    // @pre: time is initialized
    // @post: compare_time is set
    // @return: true
    // @function called: none
    bool isBotCall();

    // @param: {bool} - val: boolean value to set
    // @pre: is_bot is initilized
    // @post: is_bot is set
    // @return: true
    // @function called: none
    bool setBotCall(bool val);

    // @param: {string} - type: time to set
    // @pre: EventType is initialized
    // @post: EventType is set
    // @return: true
    // @function called: none
    bool setEventType(string type);

    // @param: {int} - time: time to set
    // @pre: Arrivaltime is initialized
    // @post: Arrival_time is set
    // @return: true
    // @function called: none
    bool setArrival(int time);

    // @param: {int} - time: time to set
    // @pre: Departure_time is initialized
    // @post: Departure_time is set
    // @return: true
    // @function called: none
    bool setDeparture(int time);

    // @param: {int} - time: time to set
    // @pre: ServiceTime is initialized
    // @post: ServiceTime is set
    // @return: true
    // @function called: none
    bool setServiceTime(int time);

    // @param: {int} - time: time to set
    // @pre: WaitTime is initialized
    // @post: WaitTime is set
    // @return: true
    // @function called: none
    bool setWaitTime(int time);

    // @param: {int} - index: time to set
    // @pre: CallTakerIndex is initialized
    // @post: CallTakerIndex is set
    // @return: true
    // @function called: none
    bool setCallTakerIndex(int index);

    // @param: {int} - time: time to set
    // @pre: TotalTime is initialized
    // @post: TotalTime is set
    // @return: true
    // @function called: none
    bool setTotalTime(int time);

    // operator overload that uses event.compare_time to compare
    bool operator<(const Event& other) const;
    bool operator>(const Event& other) const;
    bool operator!=(const Event &other) const;
    
private:
    // event important variables for keeping track of time and output stats
    int call_taker_index, arrival_time, departure_time, service_time, wait_time, total_service_time;

    // to indicate call-placed or service-ended
    string event_type;

    // is this event bot or not
    bool is_bot = false;

    // time used to compare during enqueue and dequeue
    int compare_time;
};

#endif