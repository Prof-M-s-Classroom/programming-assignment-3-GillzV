[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/K_t6ffJX)
# Prim's Algorithm with Min Heap and Adjacency Matrix

## Author
Gilbert Venegas

## Description
Briefly describe what your program does and how the code is structured.

My program uses Prim's Algorithm to compute the MST of a weighted, undirected graph. I used
an adjacency matrix for the graph and I made a min heap to select the next vertex with the smallest 
edge weight. 

## Files
- graph.h / graph.cpp
- heap.h / heap.cpp
- main.cpp (unchanged)
- README.md

## How to Compile and Run
This project was developed and tested in CLion.  
Run directly from the IDE.

## Time Complexity Analysis


| Operation            | Time Complexity |
|----------------------|-----------------|
| Insert in MinHeap    | O(logV)         |
| Extract Min          | O(logV)         |
| Decrease Key         | O(logV)         |
| Prim’s MST Overall   | O(V^2)          |

_Explain why your MST implementation has the above runtime._
 The Insert in Minheap fixes the heap using bubble up after inserting a new element, which takes 
O(logV) time in the worst case. In the extract min operation, it is swapping roots with the last 
in the heap, and calls minHeapify which is also a O(logV) time complexity. The decrease key is also 
logv time complexity because it moves the key up the heap using bubble up. The overall is V^2 
because I used an adjacency matrix so it goes through all the vertices and then it 
scans the neighbors so its V^2.


## Test Case Description
The test case was
g.addEdge(0, 1, 2);
g.addEdge(0, 3, 6);
g.addEdge(1, 2, 3);
g.addEdge(1, 3, 8);
g.addEdge(1, 4, 5);
g.addEdge(2, 4, 7);
g.addEdge(3, 4, 9);

The output I got was
Edge   Weight
0 - 1    2
1 - 2    3
0 - 3    6
1 - 4    5
Total Weight of MST: 16



