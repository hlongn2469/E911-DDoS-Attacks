
// main.cpp
// @Author: Kray Nguyen
// 2/26/2021
// Input: num of call takers, legit calls, legit service time, num of bots
// Output: Average total service time
// Usage: ./a.out 28 887 120 1000
// Assumption: only 4 parameters are passed through the command line
// Assumption: the event loop only works until the arrival time reaches 3600
// Major algorithms: Priority queue implemented as min heap to sort the most urgency event to be processed first
#include <iostream>
#include <ostream>
#include <fstream>
#include "SimulateManager.h"

using namespace std;

int main(int argc, char *argv[]){
    int num_call_takers, num_legit_calls, legit_service_time, num_bots;
    // get input variables
    num_call_takers = atoi(argv[1]);
    num_legit_calls = atoi(argv[2]);
    legit_service_time = atoi(argv[3]);
    num_bots = atoi(argv[4]);
    
    // manager object created
    SimulateManager manager(num_call_takers, num_legit_calls, legit_service_time, num_bots);

    // generate legitimate calls
    manager.generateLegitCalls();

    // generate bot calls
    manager.generateBot();

    // process the PQ once the calls are inserted into the PQ
    manager.process();

    // print output
    manager.printStats();

    return 0;
}   