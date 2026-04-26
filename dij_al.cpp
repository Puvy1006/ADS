

#include <iostream>
using namespace std;

#define V 5
#define INF 9999

int main() {

    int G[V][V] = {
        {0, 10, 0, 30, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60},
        {100, 0, 10, 60, 0}
    };

    int dist[V];
    bool visited[V];

    // Step 1: initialize
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = false;
    }

    dist[0] = 0; // source = 0

    // Step 2: main loop
    for (int count = 0; count < V - 1; count++) {

        int min = INF, u;

        // find minimum distance node
        for (int i = 0; i < V; i++) {
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        visited[u] = true;

        // update neighbors
        for (int v = 0; v < V; v++) {
            if (!visited[v] && G[u][v] != 0 &&
                dist[u] + G[u][v] < dist[v]) {

                dist[v] = dist[u] + G[u][v];
            }
        }
    }

    // Output
    cout << "Vertex  Distance from Source\n";
    for (int i = 0; i < V; i++) {
        cout << i << " \t " << dist[i] << endl;
    }

    return 0;
}

DIJKSTRA ALTERNATIVE