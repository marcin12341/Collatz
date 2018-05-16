//
// Created by marcin on 15.05.18.
//

#ifndef COLLATZ_FINAL_HEAP_H
#define COLLATZ_FINAL_HEAP_H

#define MAX_INT (4294967295/3)

class MinHeap;

class MaxHeap;

class Heap {
protected:
    struct node {
        unsigned int *key;
        int index;
        int indexMax;
        int indexMin;

        node(int index, unsigned int *key) {
            this->index = indexMin = indexMax = index;
            this->key = key;
        }
    };

public:
    node **tablica;
    int size;

    int parent(int index) {
        return (index - 1) / 2;
    }

    int left(int index) {
        return (2 * index + 1);
    }

    int right(int index) {
        return (2 * index + 2);
    }

    Heap(int);

    ~Heap();

    void insert(unsigned int *);

    virtual void swap(int, int) = 0;

    virtual void heapifyDown(int) = 0;

    virtual void heapifyUp(int) = 0;

    void buildHeap();

    virtual void collatz()=0;
};


#endif //COLLATZ_FINAL_HEAP_H
