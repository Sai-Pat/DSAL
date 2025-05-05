#include <iostream>
#include <queue>
using namespace std;

const int MAX_VERTICES = 100; // Set a limit for maximum number of vertices

class Graph {
public:
    int V;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];

    Graph(int vertices) {
        V = vertices;
        for (int i = 0; i < V; i++) {
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
        bool visited[MAX_VERTICES] = {false}; // Local static-sized array
        recursiveBFS(startVertex, visited);
        cout << endl;
    }

    void recursiveBFS(int vertex, bool* visited) {
        static queue<int> q;
        static bool initialized = false;

        if (!initialized) {
            q.push(vertex);
            visited[vertex] = true;
            initialized = true;
        }

        if (!q.empty()) {
            vertex = q.front();
            q.pop();
            cout << vertex << " ";

            for (int i = 0; i < V; i++) {
                if (adjMatrix[vertex][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }

            recursiveBFS(vertex, visited);
        }

        // Reset static variables after completion to allow reuse
        if (q.empty()) {
            initialized = false;
        }
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
