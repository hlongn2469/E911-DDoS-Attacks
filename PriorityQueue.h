  
// PriorityQueue.h
// @Author: Kray Nguyen
// 2/26/2021
// this class represents a min-heap to store Event values based on its urgency (arrival/departure time)

#ifndef _PQ_
#define _PQ_
#include <iostream>
#include <string>
#include <vector>
#include "Event.h"

using namespace std;

class PriorityQueue {

    // @pre: min_heap is initialized
    // @post: event object in the min_heap vector is printed
    // @return: none
    // @function called: none
    friend ostream& operator<<(ostream & the_stream, const PriorityQueue& rhs){
        for(int i = 0; i < rhs.min_heap.size(); i++){
            the_stream << rhs.min_heap.at(i) << " at index: " << i << endl;
        }
        return the_stream;
    }
public:

    // @pre: class is instantiated
    // @post: size is set to 0
    // @return: none
    // @function called: none
    PriorityQueue();

    // @pre: min_heap is initialized
    // @post: none
    // @return: true if min_heap is empty
    // @function called: none
    bool isEmpty() ;

    // @param {Event} - value: value needs to be inserted
    // @pre: min_heap is initialized
    // @post: value added to vector and bubble up so it remains min heap structure
    // @return: none
    // @function called: bubbleup
    void enqueue(Event value);

    // @pre: size is initialized
    // @post: none
    // @return: size of min_heap
    // @function called: none
    int getSize();

    // @pre: min_heap is instantiated
    // @post: value deleted from vector and bubble down so it remains min heap structure
    // @return: Event object that is at first element of vector
    // @function called: bubbleDown()
    Event dequeue();

    // @pre: min_heap is instantiated
    // @post: none
    // @return: first element of min_heap
    // @function called: none
    Event peek();


private:
    // store min_heap values
    vector<Event> min_heap;

    // keep track of size
    int size;

    // @param {int} - size: initial index to bubble up
    // @param {Event} - value: value needs to be inserted
    // @pre: enqueue() is called
    // @post: value are swapped until correct order to maintain min heap structure
    // @return: none
    // @function called: swap()
    void bubbleUp(int size, Event val);
    
    // @param {int} - size: initial index to bubble down
    // @param {Event} - value: value needs to be deleted
    // @pre: dequeue() is called
    // @post: value are swapped until correct order to maintain min heap structure
    // @return: none
    // @function called: swap()
    void bubbleDown(int size, Event val);

    // @param {Event*} - val1: First value needs to be swapped
    // @param {Event*} - val2: Second value needs to be swapped
    // @pre: Event objects are valid
    // @post: pointers of 2 events are swapped
    // @return: none
    // @function called: none
    void swap(Event* val1, Event* val2);

    // @param {int} - index: current index to find 
    // @pre: input is valid
    // @post: none
    // @return: parent node index of the current child is returned 
    // @function called: none
    int getParent(int index);

    // @param {int} - index: current index to find 
    // @pre: input is valid
    // @post: none
    // @return: left child node index of the current node 
    // @function called: none
    int getLeftChild(int index);

    // @param {int} - index: current index to find 
    // @pre: input is valid
    // @post: none
    // @return: right child node index of the current node 
    // @function called: none
    int getRightChild(int index);

};

#endif