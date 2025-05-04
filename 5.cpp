#include <iostream>
#include <cstring>
using namespace std;

class Graph {
    int V;
    int** adj;

public:
    Graph(int V);
    void addEdge(int u, int v, int cost);
    bool isConnected();
    void DFS(int v, bool visited[]);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new int*[V];
    for (int i = 0; i < V; i++) {
        adj[i] = new int[V];
        for (int j = 0; j < V; j++) {
            adj[i][j] = 0;
        }
    }
}

void Graph::addEdge(int u, int v, int cost) {
    adj[u][v] = cost;
    adj[v][u] = cost;
}

void Graph::DFS(int v, bool visited[]) {
    visited[v] = true;
    for (int i = 0; i < V; i++) {
        if (adj[v][i] != 0 && !visited[i]) {
            DFS(i, visited);
        }
    }
}

bool Graph::isConnected() {
    bool* visited = new bool[V];
    memset(visited, false, sizeof(bool) * V);

    DFS(0, visited);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int V = 5;
    Graph g(V);

    g.addEdge(0, 1, 50);
    g.addEdge(0, 2, 100);
    g.addEdge(1, 3, 200);
    g.addEdge(2, 3, 150);
    g.addEdge(3, 4, 250);

    if (g.isConnected()) {
        cout << "The graph is connected." << endl;
    } else {
        cout << "The graph is not connected." << endl;
    }

    return 0;
}
