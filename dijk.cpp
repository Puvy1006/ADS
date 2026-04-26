#include<iostream>
#include <limits.h>   // for INT_MAX (infinity value)
using namespace std;

// Function to find the vertex with the minimum distance
int minDistance(int dist[], bool Tset[]) {
    int min = INT_MAX;   // start with very large value
    int min_index;       // will store index of smallest distance

    // loop through all vertices
    for (int i = 0; i < 6; i++) {
        // pick the smallest distance vertex that is not yet visited
        if (Tset[i] == false && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }

    return min_index; // return index of minimum distance vertex
}

// Function to print final shortest distances
void output(int dist[]) {
    cout << "Vertex \t Distance from Source\n";

    for (int i = 0; i < 6; i++) {
        char node = 65 + i;  // converts 0->A, 1->B, ...
        cout << node << " \t\t " << dist[i] << endl;
    }
}

// Dijkstra Algorithm function
void dijkstraAlgorithm(int graph[6][6], int src)
{
    int dist[6];   // stores shortest distance from source
    bool Tset[6];  // keeps track of visited vertices

    // Step 1: initialize all distances as infinite and visited as false
    for (int i = 0; i < 6; i++) {
        dist[i] = INT_MAX;  // infinity
        Tset[i] = false;    // not visited
    }

    // distance of source from itself is always 0
    dist[src] = 0;

    // Step 2: find shortest path for all vertices
    for (int count = 0; count < 6 - 1; count++) {

        // pick the minimum distance vertex from unvisited set
        int u = minDistance(dist, Tset);

        // mark that vertex as visited
        Tset[u] = true;

        // update distance of adjacent vertices
        for (int v = 0; v < 6; v++) {

            // conditions to update:
            // 1. vertex not visited
            // 2. edge exists (graph[u][v] != 0)
            // 3. current distance is not infinity
            // 4. new distance is smaller than old distance
            if (!Tset[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v]) {

                // update distance
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Step 3: print final result
    output(dist);
}

int main()
{
    // adjacency matrix of graph (6 vertices: A to F)
    // 0 means no direct edge
    int graph[6][6] = {
        {0, 1, 2, 0, 0, 0},  // A
        {1, 0, 1, 0, 3, 0},  // B
        {2, 1, 0, 2, 2, 0},  // C
        {0, 0, 2, 0, 1, 1},  // D
        {0, 3, 2, 1, 0, 2},  // E
        {0, 0, 0, 1, 2, 0}   // F
    };

    // run Dijkstra from source vertex A (index 0)
    dijkstraAlgorithm(graph, 0);

    return 0;
}

DIJKSTRA ALGORITHM