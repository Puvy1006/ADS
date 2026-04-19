#include <iostream>
#include <queue>
#include <stack>
using namespace std;

#define MAX 10

int maze[MAX][MAX];
bool visited[MAX][MAX];
int n, m;

// Directions
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// Check valid cell
bool isValid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m &&
            maze[x][y] == 0 && !visited[x][y]);
}

// SHOW MAZE
void displayMaze() {
    cout << "\nMaze Layout:\n";
    cout << "0 = Open Path, 1 = Blocked\n\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
}

// BFS
void BFS(int sx, int sy, int gx, int gy) {
    queue<pair<int,int>> q;
    q.push({sx, sy});
    visited[sx][sy] = true;

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        int x = curr.first;
        int y = curr.second;

        if (x == gx && y == gy) {
            cout << "Path Found using BFS\n";
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isValid(nx, ny)) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    cout << "No Path Found using BFS\n";
}

// DFS 
void DFS(int sx, int sy, int gx, int gy) {
    stack<pair<int,int>> st;
    st.push({sx, sy});
    visited[sx][sy] = true;

    while (!st.empty()) {
        auto curr = st.top();
        st.pop();

        int x = curr.first;
        int y = curr.second;

        if (x == gx && y == gy) {
            cout << "Path Found using DFS\n";
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isValid(nx, ny)) {
                visited[nx][ny] = true;
                st.push({nx, ny});
            }
        }
    }

    cout << "No Path Found using DFS\n";
}

// Reset visited
void resetVisited() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            visited[i][j] = false;
}

// MAIN
int main() {
    int choice;
    int sx, sy, gx, gy;

    cout << "Enter rows and columns: \n";
    cin >> n >> m;

    cout << "Enter maze (0=open, 1=blocked):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> maze[i][j];

    cout << "Enter start position (x y): \n ";
    cin >> sx >> sy;

    cout << "Enter goal position (x y): \n";
    cin >> gx >> gy;

    do {
        cout << "\n MENU \n";
        cout << "1. Show Maze\n";
        cout << "2. BFS (Queue)\n";
        cout << "3. DFS (Stack)\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        resetVisited();

        switch (choice) {

        case 1:
            displayMaze();
            break;

        case 2:
            BFS(sx, sy, gx, gy);
            break;

        case 3:
            DFS(sx, sy, gx, gy);
            break;

        case 4:
            cout << "Exiting \n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}

