//
// Created by marcin on 15.05.18.
//

#include "MinHeap.h"
#include "MaxHeap.h"

MinHeap::MinHeap(int n) : Heap(int()) {
    tablica = new node *[n];
    size = 0;
}

MinHeap::~MinHeap() {
    delete tablica;
}

void MinHeap::addHeap(MaxHeap *maxHeap) {
    this->maxHeap = maxHeap;
}

void MinHeap::heapifyDown(int i) {
    if (size == 0) {
        return;
    }
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < size && *tablica[l]->key <= *tablica[i]->key) {
        if (*tablica[l]->key == *tablica[i]->key) {
            if (tablica[l]->index < tablica[i]->index) {
                smallest = l;
            }
        } else {
            smallest = l;
        }
    }
    if (r < size && *tablica[r]->key <= *tablica[smallest]->key) {
        if (*tablica[r]->key == *tablica[smallest]->key) {
            if (tablica[r]->index < tablica[smallest]->index) {
                smallest = r;
            }
        } else {
            smallest = r;
        }
    }
    if (smallest != i) {
        swap(i, smallest);
        heapifyDown(smallest);
    }
}

void MinHeap::heapifyUp(int i) {
    if (size == 0) {
        return;
    }
    while (i != 0 && *tablica[parent(i)]->key >= *tablica[i]->key) {
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

void MinHeap::swap(int x, int y) {
    maxHeap->tablica[tablica[x]->indexMax]->indexMin = y;
    maxHeap->tablica[tablica[y]->indexMax]->indexMin = x;
    tablica[x]->indexMin = y;
    tablica[y]->indexMin = x;
    node *temp;
    temp = tablica[x];
    tablica[x] = tablica[y];
    tablica[y] = temp;
}

void MinHeap::collatz() {
    if (size == 0) {
        return;
    }
    if (*tablica[0]->key % 2 == 0) {
        *tablica[0]->key /= 2;
        if (*tablica[0]->key == 1) {
            int index = tablica[0]->indexMax;
            remove(index);
        } else {
            maxHeap->heapifyDown(tablica[0]->indexMax);
        }
    } else {
        if (*tablica[0]->key > MAX_INT) {
            *tablica[0]->key = 0;
            int index = tablica[0]->indexMax;
            remove(index);
        } else {
            *tablica[0]->key = 3 * *tablica[0]->key + 1;
            maxHeap->heapifyUp(tablica[0]->indexMax);
        }
        heapifyDown(0);
    }
}

void MinHeap::remove(int index) {
    if (size == 0) {
        return;
    }
    this->size--;
    maxHeap->size--;
    if (index != size) {
        maxHeap->swap(index, size);
        maxHeap->heapifyUp(index);
        maxHeap->heapifyDown(index);
    }
    swap(0, size);
    heapifyDown(0);
}