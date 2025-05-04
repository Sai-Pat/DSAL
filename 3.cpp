#include <iostream>
#include <queue>
using namespace std;

class Graph {
public:
    int V;
    int** adjMatrix;

    Graph(int vertices) {
        V = vertices;
        adjMatrix = new int*[V];
        for (int i = 0; i < V; i++) {
            adjMatrix[i] = new int[V];
            for (int j = 0; j < V; j++) {
                adjMatrix[i][j] = 0; // Initialize all edges to 0
            }
        }
    }

    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // Since the graph is undirected
    }

    void BFS(int startVertex) {
        bool* visited = new bool[V];
        for (int i = 0; i < V; i++) {
            visited[i] = false; // Mark all vertices as not visited
        }

        queue<int> q;
        visited[startVertex] = true;
        q.push(startVertex);

        while (!q.empty()) {
            int vertex = q.front();
            q.pop();
            cout << vertex << " ";

            for (int i = 0; i < V; i++) {
                if (adjMatrix[vertex][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);

    cout << "BFS starting from vertex 0: ";
    g.BFS(0);

    return 0;
}
