  
// PriorityQueue.cpp
// @Author: Kray Nguyen
// 2/26/2021
// this class represents a min-heap to store Event values based on its urgency (arrival/departure time)
#include "PriorityQueue.h"

#include <string>
#include <iostream>

using namespace std;

// @pre: class is instantiated
// @post: size is set to 0
// @return: none
// @function called: none
PriorityQueue::PriorityQueue() {
    size = 0;
}


// @pre: min_heap is initialized
// @post: none
// @return: true if min_heap is empty
// @function called: none
bool PriorityQueue::isEmpty(){
    return getSize() == 0;
}

// @pre: size is initialized
// @post: none
// @return: size of min_heap
// @function called: none
int PriorityQueue::getSize(){
    return min_heap.size();
}

// @pre: min_heap is instantiated
// @post: none
// @return: first element of min_heap
// @function called: none
Event PriorityQueue::peek(){
    // always look at the minimum element which is at index 1
    return min_heap.at(0);
}

// @param {Event} - value: value needs to be inserted
// @pre: min_heap is initialized
// @post: value added to vector and bubble up so it remains min heap structure
// @return: none
// @function called: bubbleup
void PriorityQueue::enqueue(Event val){
    // add to rightmost leaf
    min_heap.push_back(val);

    int bubbling_index = getSize() - 1;    
    
    // bubble up
    bubbleUp(bubbling_index, val);
}

// @pre: min_heap is instantiated
// @post: value deleted from vector and bubble down so it remains min heap structure
// @return: Event object that is at first element of vector
// @function called: bubbleDown()
Event PriorityQueue::dequeue(){
    Event delete_value, rightmost_leaf;
    if(isEmpty()){
        cerr << "Empty priority queue" << endl;
    } else {
        // get first element to return 
        delete_value = peek();
        rightmost_leaf = min_heap.at(size);

        // change root element = to the rightmost leaf
        min_heap[0] = min_heap.back();

        // delete root
        min_heap.pop_back();

        // bubble down
        bubbleDown(0, rightmost_leaf);
    }
    return delete_value;
}

// @param {int} - size: initial index to bubble down
    // @param {Event} - value: value needs to be deleted
    // @pre: dequeue() is called
    // @post: value are swapped until correct order to maintain min heap structure
    // @return: none
    // @function called: swap()
void PriorityQueue::bubbleDown(int bubbling_index, Event val){
    int bubbling_target, left_child, right_child;
    left_child = getLeftChild(bubbling_index);
    right_child = getRightChild(bubbling_index);

    bubbling_target = bubbling_index;

    // check to see which node is the smaller child to move down
    if(left_child < getSize() && min_heap[bubbling_index] > min_heap[left_child]){
        bubbling_target = left_child;
    }

    if(right_child < getSize() && min_heap[bubbling_target] > min_heap[right_child]){
        bubbling_target = right_child;
    }

    // swap if current node is larger than the child
    if(bubbling_target != bubbling_index){
        swap(&min_heap.at(bubbling_index),&min_heap.at(bubbling_target));
        bubbleDown(bubbling_target, val);
    }
}

// @param {int} - size: initial index to bubble up
    // @param {Event} - value: value needs to be inserted
    // @pre: enqueue() is called
    // @post: value are swapped until correct order to maintain min heap structure
    // @return: none
    // @function called: swap()
void PriorityQueue::bubbleUp(int bubbling_index, Event val){

    // swap if the parent node is larger than the current node
    if(bubbling_index && min_heap.at(getParent(bubbling_index)) > min_heap.at(bubbling_index)){
        swap(&min_heap[bubbling_index], &min_heap[getParent(bubbling_index)]);
        bubbleUp(getParent(bubbling_index), val);
    }
}

// @param {int} - index: current index to find 
    // @pre: input is valid
    // @post: none
    // @return: parent node index of the current child is returned 
    // @function called: none
int PriorityQueue::getParent(int index){
    return (index - 1)/2;
}

// @param {int} - index: current index to find 
    // @pre: input is valid
    // @post: none
    // @return: left child node index of the current node 
    // @function called: none
int PriorityQueue::getLeftChild(int index){
    return (2*index +1);
}

// @param {int} - index: current index to find 
    // @pre: input is valid
    // @post: none
    // @return: right child node index of the current node 
    // @function called: none
int PriorityQueue::getRightChild(int index){
    return (2*index + 2);
}

// @param {Event*} - val1: First value needs to be swapped
    // @param {Event*} - val2: Second value needs to be swapped
    // @pre: Event objects are valid
    // @post: pointers of 2 events are swapped
    // @return: none
    // @function called: none
void PriorityQueue::swap(Event* val1, Event* val2){
    Event temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}

