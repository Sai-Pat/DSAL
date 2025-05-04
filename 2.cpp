#include <iostream>
using namespace std;

class G {
public:
    int adjm[10][10];
    int V;

    G(int vor) {
        V = vor;
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                adjm[i][j] = 0;
    }

    void edge(int u, int v) {
        adjm[u][v] = 1;
        adjm[v][u] = 1;
    }

    void performDFS(int start) {
        bool visited[10] = {false};
        int stack[10]; // simple array stack
        int top = -1;

        stack[++top] = start;

        cout << "DFS Starting...\n";

        while (top != -1) {
            int curr = stack[top--];

            if (!visited[curr]) {
                visited[curr] = true;
                cout << curr << " ";

                // Push all unvisited neighbors to stack (in reverse order for correct DFS)
                for (int i = V - 1; i >= 0; i--) {
                    if (adjm[curr][i] == 1 && !visited[i]) {
                        stack[++top] = i;
                    }
                }
            }
        }
    }
};

int main() {
    G g(5);
    g.edge(0, 1);
    g.edge(0, 2);
    g.edge(1, 3);
    g.edge(1, 4);
    g.edge(2, 3);

    g.performDFS(0);
    return 0;
}
