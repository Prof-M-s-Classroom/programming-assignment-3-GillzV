#include "heap.h"
#include <climits>
#include <algorithm>

MinHeap::MinHeap(int capacity) {
    this->capacity = capacity;
    this->size = 0;
    heapArray = new int[capacity];
    keyArray = new int[capacity];
    position = new int[capacity];

    for (int i = 0; i < capacity; ++i) {
        keyArray[i] = INT_MAX;
        position[i] = -1;
    }
}

MinHeap::~MinHeap() {
    delete[] heapArray;
    delete[] keyArray;
    delete[] position;
}

bool MinHeap::isEmpty() {
    return size == 0;
}

bool MinHeap::isInMinHeap(int vertex) {
    return position[vertex] < size && position[vertex] >= 0;
}

void MinHeap::insert(int vertex, int key) {
    if (size == capacity) return;

    heapArray[size] = vertex;
    keyArray[vertex] = key;
    position[vertex] = size;

    int i = size;
    ++size;

    while (i && keyArray[heapArray[i]] < keyArray[heapArray[(i - 1) / 2]]) {
        std::swap(heapArray[i], heapArray[(i - 1) / 2]);
        position[heapArray[i]] = i;
        position[heapArray[(i - 1) / 2]] = (i - 1) / 2;
        i = (i - 1) / 2;
    }
}

int MinHeap::extractMin() {
    if (isEmpty()) return -1;

    int root = heapArray[0];
    int last = heapArray[size - 1];
    heapArray[0] = last;
    position[root] = -1;
    position[last] = 0;
    --size;
    minHeapify(0);
    return root;
}

void MinHeap::decreaseKey(int vertex, int newKey) {
    int i = position[vertex];
    keyArray[vertex] = newKey;

    while (i && keyArray[heapArray[i]] < keyArray[heapArray[(i - 1) / 2]]) {
        std::swap(heapArray[i], heapArray[(i - 1) / 2]);
        position[heapArray[i]] = i;
        position[heapArray[(i - 1) / 2]] = (i - 1) / 2;
        i = (i - 1) / 2;
    }
}

void MinHeap::minHeapify(int idx) {
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    int smallest = idx;

    if (left < size && keyArray[heapArray[left]] < keyArray[heapArray[smallest]])
        smallest = left;
    if (right < size && keyArray[heapArray[right]] < keyArray[heapArray[smallest]])
        smallest = right;

    if (smallest != idx) {
        std::swap(heapArray[idx], heapArray[smallest]);
        position[heapArray[idx]] = idx;
        position[heapArray[smallest]] = smallest;
        minHeapify(smallest);
    }
}

int MinHeap::getKey(int vertex) const {
    return keyArray[vertex];
}


