#include "graph.h"
#include "heap.h"
#include <iostream>
#include <climits>

Graph::Graph(int vertices) {
    numVertices = vertices;
    adjMatrix = new int*[vertices];
    for (int i = 0; i < vertices; ++i) {
        adjMatrix[i] = new int[vertices];
        for (int j = 0; j < vertices; ++j)
            adjMatrix[i][j] = 0;
    }
}

Graph::~Graph() {
    for (int i = 0; i < numVertices; ++i)
        delete[] adjMatrix[i];
    delete[] adjMatrix;
}

void Graph::addEdge(int u, int v, int weight) {
    adjMatrix[u][v] = weight;
    adjMatrix[v][u] = weight;
}

void Graph::primMST() {
    int* parent = new int[numVertices];
    MinHeap minHeap(numVertices);

    for (int v = 0; v < numVertices; ++v) {
        parent[v] = -1;
        minHeap.insert(v, INT_MAX);
    }

    minHeap.decreaseKey(0, 0);

    while (!minHeap.isEmpty()) {
        int u = minHeap.extractMin();

        for (int v = 0; v < numVertices; ++v) {
            int weight = adjMatrix[u][v];
            if (weight != 0 && minHeap.isInMinHeap(v) && weight < minHeap.getKey(v)) {
                parent[v] = u;
                minHeap.decreaseKey(v, weight);
            }
        }
    }

    int totalWeight = 0;
    std::cout << "Edge   Weight\n";
    for (int i = 1; i < numVertices; ++i) {
        std::cout << parent[i] << " - " << i << "    " << adjMatrix[i][parent[i]] << "\n";
        totalWeight += adjMatrix[i][parent[i]];
    }
    std::cout << "Total Weight of MST: " << totalWeight << "\n";

    delete[] parent;
}


