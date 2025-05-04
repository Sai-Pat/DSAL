#include <iostream>
using namespace std;

class Graph {
public:
    int V;
    int adjMatrix[10][10]; // fixed size for simplicity

    Graph(int vertices) {
        V = vertices;
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                adjMatrix[i][j] = 0;
    }

    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // undirected
    }

    void DFS(int v, bool visited[]) {
        visited[v] = true;
        cout << v << " ";
        for (int i = 0; i < V; i++) {
            if (adjMatrix[v][i] == 1 && !visited[i]) {
                DFS(i, visited);
            }
        }
    }

    void performDFS(int startVertex) {
        bool visited[10] = {false}; // assumes max 10 vertices
        cout << "DFS starting from vertex " << startVertex << ": ";
        DFS(startVertex, visited);
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

    g.performDFS(0);
    return 0;
}
