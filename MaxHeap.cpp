//
// Created by marcin on 15.05.18.
//

#include "MaxHeap.h"
#include "MinHeap.h"

MaxHeap::MaxHeap(int n) : Heap(int()) {
    tablica = new node *[n];
    size = 0;
}

MaxHeap::~MaxHeap() {
    delete tablica;
}

void MaxHeap::addHeap(MinHeap *minHeap) {
    this->minHeap = minHeap;
}

void MaxHeap::heapifyDown(int i) {
    if (size == 0) {
        return;
    }
    int l = left(i);
    int r = right(i);
    int largest = i;
    if (l < size && *tablica[l]->key >= *tablica[i]->key) {
        if (*tablica[l]->key == *tablica[i]->key) {
            if (tablica[l]->index < tablica[i]->index) {
                largest = l;
            }
        } else {
            largest = l;
        }
    }
    if (r < size && *tablica[r]->key >= *tablica[largest]->key) {
        if (*tablica[r]->key == *tablica[largest]->key) {
            if (tablica[r]->index < tablica[largest]->index) {
                largest = r;
            }
        } else {
            largest = r;
        }
    }
    if (largest != i) {
        swap(i, largest);
        heapifyDown(largest);
    }
}

void MaxHeap::heapifyUp(int i) {
    if (size == 0) {
        return;
    }
    while (i != 0 && *tablica[parent(i)]->key <= *tablica[i]->key) {
        if (*tablica[parent(i)]->key == *tablica[i]->key) {
            if (tablica[parent(i)]->index > tablica[i]->index) {
                swap(i, parent(i));
                i = parent(i);
            } else {
                break;
            }
        } else {
            swap(i, parent(i));
            i = parent(i);
        }
    }
}

void MaxHeap::swap(int x, int y) {
    minHeap->tablica[tablica[x]->indexMin]->indexMax = y;
    minHeap->tablica[tablica[y]->indexMin]->indexMax = x;
    tablica[x]->indexMax = y;
    tablica[y]->indexMax = x;
    node *temp;
    temp = tablica[x];
    tablica[x] = tablica[y];
    tablica[y] = temp;
}

void MaxHeap::collatz() {
    if (size == 0) {
        return;
    }
    if (*tablica[0]->key % 2 == 0) {
        *tablica[0]->key /= 2;
        if (*tablica[0]->key == 1) {
            int index = tablica[0]->indexMin;
            remove(index);
        } else {
            minHeap->heapifyUp(tablica[0]->indexMin);
            heapifyDown(0);
        }
    } else {
        if (*tablica[0]->key > MAX_INT) {
            *tablica[0]->key = 0;
            int index = tablica[0]->indexMin;
            remove(index);
        } else {
            *tablica[0]->key = 3 * *tablica[0]->key + 1;
            minHeap->heapifyDown(tablica[0]->indexMin);
        }
    }
}

void MaxHeap::remove(int index) {
    this->size--;
    minHeap->size--;
    if (index != size) {
        minHeap->swap(index, size);
        minHeap->heapifyUp(index);
        minHeap->heapifyDown(index);
    }
    swap(0, size);
    heapifyDown(0);
}