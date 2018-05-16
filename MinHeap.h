//
// Created by marcin on 15.05.18.
//

#ifndef COLLATZ_FINAL_MINHEAP_H
#define COLLATZ_FINAL_MINHEAP_H


#include "Heap.h"
#include "MaxHeap.h"

class MinHeap : public Heap {
public:
    MaxHeap *maxHeap;

    MinHeap(int);

    ~MinHeap();

    void addHeap(MaxHeap *);

    void swap(int, int);

    void heapifyDown(int) override;

    void heapifyUp(int) override;

    void collatz() override;

    void remove(int);
};


#endif //COLLATZ_FINAL_MINHEAP_H
