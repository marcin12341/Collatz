//
// Created by marcin on 15.05.18.
//

#ifndef COLLATZ_FINAL_MAXHEAP_H
#define COLLATZ_FINAL_MAXHEAP_H


#include "Heap.h"
#include "MinHeap.h"

class MaxHeap : public Heap {
public:
    MinHeap *minHeap;

    MaxHeap(int);

    ~MaxHeap();

    void addHeap(MinHeap *);

    void swap(int, int);

    void heapifyDown(int) override;

    void heapifyUp(int) override;

    void collatz() override;

    void remove(int);
};


#endif //COLLATZ_FINAL_MAXHEAP_H
