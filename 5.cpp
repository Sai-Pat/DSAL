#include <iostream>
using namespace std;

int graph[10][10], visited[10], n;

void dfs(int node) {
    visited[node] = 1;
    for (int i = 0; i < n; i++)
        if (graph[node][i] && !visited[i])
            dfs(i);
}

int main() {
    int edges, u, v, cost;
    cout << "Enter number of cities and flights: ";
    cin >> n >> edges;
    
    for (int i = 0; i < edges; i++) {
        cin >> u >> v >> cost;
        graph[u][v] = graph[v][u] = cost; // undirected graph with cost
    }

    dfs(0); // start from first city

    int connected = 1;
    for (int i = 0; i < n; i++)
        if (!visited[i]) connected = 0;

    if (connected)
        cout << "Graph is Connected\n";
    else
        cout << "Graph is Not Connected\n";

    return 0;
}
