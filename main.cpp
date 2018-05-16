#include <iostream>
#include "Heap.h"
#include "MinHeap.h"
#include "MaxHeap.h"

int main() {
    int n, q, k;
    char c;
    scanf("%u", &n);
    auto *tab = new unsigned int[n];

    MaxHeap maxHeap(n);
    MinHeap minHeap(n);

    maxHeap.addHeap(&minHeap);
    minHeap.addHeap(&maxHeap);

    for (int i = 0; i < n; i++) {
        scanf("%d", &tab[i]);
        if (tab[i] != 1) {
            maxHeap.insert(&tab[i]);
            minHeap.insert(&tab[i]);
        }
    }

    minHeap.buildHeap();
    maxHeap.buildHeap();

    scanf("%u", &q);
    for (int i = 0; i < q; i++) {
        scanf("%u %c", &k, &c);
        if (c == 's') {
            for (int j = 0; j < k; j++) {
                minHeap.collatz();
            }
        } else {
            for (int j = 0; j < k; j++) {
                maxHeap.collatz();
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (tab[i] == 0) {
            printf("m ");
        } else {
            printf("%u ", tab[i]);
        }
    }
    printf("\n");
    return 0;
}