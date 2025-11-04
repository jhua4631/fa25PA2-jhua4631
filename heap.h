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
        // in order to re-order
        upheap(size, weightArr);
        size++;
    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        if (size == 0) {
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
            if(weightArr[data[pos]] >= weightArr[data[parent]])
                break;

            swap(data[pos], data[parent]);
            pos = parent;
        }
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        while(2 * pos + 1 < size) {
            int leftChild = 2 * pos + 1;
            int rightChild = 2 * pos + 2;
            int smallest = leftChild;

            // if leftChild larger than rightChild, smallest = rightChild
            if(leftChild < size && weightArr[data[leftChild]] > weightArr[data[rightChild]]) {
                smallest = rightChild;
            }

            // if rightChild larger than leftChild, smallest = leftChild
            if(rightChild < size && weightArr[data[rightChild]] > weightArr[data[leftChild]]) {
                smallest = leftChild;
            }

            if(weightArr[pos] <= weightArr[smallest]) break;
                swap(data[pos], data[smallest]);
                pos = smallest; // (?)

        }
    }
};

#endif