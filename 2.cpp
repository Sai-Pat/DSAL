#include <iostream>
#include <stack>
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
                adjMatrix[i][j] = 0;
            }
        }
    }

    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    void DFS(int startVertex) {
        bool* visited = new bool[V];
        for (int i = 0; i < V; i++) {
            visited[i] = false;
        }

        stack<int> s;
        s.push(startVertex);

        while (!s.empty()) {
            int vertex = s.top();
            s.pop();

            if (!visited[vertex]) {
                visited[vertex] = true;
                cout << vertex << " ";
            }

            for (int i = V - 1; i >= 0; i--) {
                if (adjMatrix[vertex][i] == 1 && !visited[i]) {
                    s.push(i);
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

    cout << "DFS starting from vertex 0: ";
    g.DFS(0);

    return 0;
}
