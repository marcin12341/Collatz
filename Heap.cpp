//
// Created by marcin on 15.05.18.
//

#include "Heap.h"

Heap::Heap(int n) {
    tablica = new node *[n];
    size = 0;
}

void Heap::buildHeap() {
    if (size == 0) {
        return;
    }
    for (int i = (size - 2) / 2; i >= 0; i--) {
        heapifyDown(i);
    }
}

void Heap::insert(unsigned int *key) {
    auto *temp = new node(size, key);
    tablica[size] = temp;
    size++;
}

Heap::~Heap() {

}
