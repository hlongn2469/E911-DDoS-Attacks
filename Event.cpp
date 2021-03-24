// Event.cpp
// @Author: Kray Nguyen
// 2/26/2021
// This class store time tracking variables such as arrival, departure, wait, and service time 
// of an event
#include "Event.h"

// @pre: class is instantiated
    // @post: wait time is set to 0
    // @return: none
    // @function called: none
Event::Event(){
    wait_time = 0;
    event_type = " ";
}

// @pre: other is a valid event
    // @post: deep copy object created
    // @return: none
    // @function called: none
Event::Event(const Event& other){
    event_type = other.event_type;
    is_bot = other.is_bot;
    arrival_time = other.arrival_time;
    departure_time = other.departure_time;
    service_time = other.service_time;
    call_taker_index = other.call_taker_index;
    total_service_time = other.total_service_time;
    wait_time = other.wait_time;
    compare_time = other.compare_time;
}

// @pre: valid inputs
    // @post: variables are setted through parameterized constructor
    // @return: none
    // @function called: none
Event::Event(int a, int s, bool bot, string type, int d, int w){
    wait_time = w;
    event_type = type;
    arrival_time = a;
    service_time = s;
    departure_time = d;
    compare_time = a;
    is_bot = bot;
    total_service_time = 0;
}

bool Event::isBotCall(){
    return is_bot;
}

bool Event::setArrival(int time){
    arrival_time = time;
    compare_time = time;
    return true;
}

bool Event::setDeparture(int time){
    departure_time = time;
    compare_time = time;
    total_service_time = service_time + wait_time;
    return true;
}

// @param: {int} - time: time to set
    // @pre: ServiceTime is initialized
    // @post: ServiceTime is set
    // @return: true
    // @function called: none
bool Event::setServiceTime(int time){
    service_time = time;
    return true;
}

// @param: {int} - time: time to set
    // @pre: time is initialized
    // @post: compare_time is set
    // @return: true
    // @function called: none
bool Event::setBotCall(bool val){
    is_bot = val;
    return true;
}

// @param: {int} - time: time to set
    // @pre: TotalTime is initialized
    // @post: TotalTime is set
    // @return: true
    // @function called: none
bool Event::setTotalTime(int time){
    total_service_time = time;
    return true;
}

// @param: {int} - index: time to set
    // @pre: CallTakerIndex is initialized
    // @post: CallTakerIndex is set
    // @return: true
    // @function called: none
bool Event::setCallTakerIndex(int index){
    call_taker_index = index;
    return true;
}

// @pre: service_time is initialized
    // @post: none
    // @return: service_time
    // @function called: none
int Event::getServiceTime(){
    return service_time;
}

// @pre: TotalTime is initialized
    // @post: none
    // @return: TotalTime
    // @function called: none
int Event::getTotalTime(){
    return total_service_time;
}

// @pre: CallTakerIndex is initialized
    // @post: none
    // @return: CallTakerIndex
    // @function called: none
int Event::getCallTakerIndex(){
    return call_taker_index;
}

// @param: {int} - time: time to set
    // @pre: WaitTime is initialized
    // @post: WaitTime is set
    // @return: true
    // @function called: none
bool Event::setWaitTime(int time){
    wait_time = time;
    return true;
}

// @param: {int} - time: time to set
    // @pre: time is initialized
    // @post: compare_time is set
    // @return: true
    // @function called: none
bool Event::setCompareTime(int time){
    compare_time = time;
    return true;
}

// @param: {string} - type: time to set
    // @pre: EventType is initialized
    // @post: EventType is set
    // @return: true
    // @function called: none
bool Event::setEventType(string type){
    event_type = type;
    return true;
}

// @pre: CompareTime is initialized
    // @post: none
    // @return: CompareTime
    // @function called: none
int Event::getCompareTime(){
    return compare_time;
}

// @pre: event_type is initialized
    // @post: none
    // @return: string event_type
    // @function called: none
string Event::getEventType(){
    return event_type;
}

// @pre: arrival_time is initialized
    // @post: none
    // @return: arrival_time
    // @function called: 
int Event::getArrival(){
    return arrival_time;
}

// @pre: departure_time is initialized
    // @post: none
    // @return: departure_time
    // @function called: none
int Event::getDeparture(){
    return departure_time;
}

// @pre: wait_time is initialized
    // @post: none
    // @return: string wait_time
    // @function called: none
int Event::getWaitTime(){
    return wait_time;
}

// operator less than
bool Event::operator<(const Event& other) const {
    return compare_time < other.compare_time;
}

// operator greater
bool Event::operator>(const Event& other) const {
    return compare_time > other.compare_time;
}

// Event& Event::operator=(const Event &other){
//     if(*this != other){
//         event_type = other.event_type;
//         is_bot = other.is_bot;
//         arrival_time = other.arrival_time;
//         departure_time = other.departure_time;
//         service_time = other.service_time;
//         call_taker_index = other.call_taker_index;
//         total_service_time = other.total_service_time;
//         wait_time = other.wait_time;
//         compare_time = other.compare_time;
//     }
//     return *this;
// }

bool Event::operator!=(const Event &other) const{
    return arrival_time != other.arrival_time;
}