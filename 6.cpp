#include <iostream>
using namespace std;

#define V 5

int main() {

    // Department names
    string dept[V] = {"Admin", "Computer", "IT", "Mechanical", "Library"};

    // Adjacency Matrix (Distances)
    int G[V][V] = {
        {0, 4, 0, 5, 2},
        {4, 0, 1, 3, 0},
        {0, 1, 0, 8, 0},
        {5, 3, 8, 0, 2},
        {2, 0, 0, 2, 0},
    };

    // Step 2: Visited array
    int visited[V] = {0};
    visited[0] = 1; // Start from Admin

    int no_edges = 0;
    int total_cost = 0;

    cout << "Minimum Spanning Tree (Prim's Algorithm)\n";
    cout << "Edge : Distance\n";

    while (no_edges < V - 1) {
        int min = 999;
        int r = 0, c = 0;

        // Traverse visited vertices
        for (int i = 0; i < V; i++) {
            if (visited[i]) {
                for (int j = 0; j < V; j++) {

                    if (!visited[j] && G[i][j] != 0) {
                        if (G[i][j] < min) {
                            min = G[i][j];
                            r = i;
                            c = j;
                        }
                    }
                }
            }
        }

        cout << dept[r] << " - " << dept[c] << " : " << min << " meters\n";

        total_cost += min;
        visited[c] = 1;
        no_edges++;
    }

    cout << "\nTotal Distance of MST: " << total_cost << " meters\n";

    return 0;
}
