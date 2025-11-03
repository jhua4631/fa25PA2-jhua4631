//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64]; // i assume size of the array
    int size; // counter of the size

    MinHeap() {
        size = 0;
    }

    void push(int idx, int weightArr[]) {
        // TODO: insert index at end of heap, restore order using upheap()
        data[size] = idx;
        size++;

        // in order to re-order
        upheap(idx, weightArr);
    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        if(data[size] == 0) {
            return -1;
        }

        //should store the min index before its deleted (?)
        int minIndex = data[0];

        data[0] = data[size - 1];
        size--;

        // Replace root with last element, then call downheap()
        downheap(0, weightArr);
        return minIndex;
        //return -1; // placeholder
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
        while(pos > 0) {
            int parent = (pos - 1) / 2;
            // probably works not testing right now
            if(weightArr[data[pos]] < weightArr[data[parent]]) {
                swap(data[pos], data[parent]);
                pos = parent;
            }
            else {
                break; // maybe?
            }
        }
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        while(pos < size) {

        }

        int leftChild = 2 * pos + 1;
        int rightChild = 2 * pos + 2;
        int smallest = pos;

        //
        if(leftChild < size && weightArr[leftChild] > weightArr[smallest]) {
            smallest = leftChild;
        }

        //
        if(rightChild < size && weightArr[rightChild] > weightArr[smallest]) {
            smallest = rightChild;
        }

        if(smallest == pos) {
            swap(data[pos], data[smallest]);
            pos = smallest; // (?)
        }
    }
};

#endif