#include <iostream>
using namespace std;

class OptimalBST {
public:
    int *keys;
    float *probabilities;
    int n;

    OptimalBST(int n) {
        this->n = n;
        keys = new int[n];
        probabilities = new float[n];
    }

    void input() {
        cout << "Enter keys: ";
        for (int i = 0; i < n; i++) {
            cin >> keys[i];
        }

        cout << "Enter probabilities: ";
        for (int i = 0; i < n; i++) {
            cin >> probabilities[i];
        }
    }

    void computeOptimalBST() {
        float **cost = new float*[n+1];
        int **root = new int*[n+1];

        for (int i = 0; i <= n; i++) {
            cost[i] = new float[n+1];
            root[i] = new int[n+1];
        }

        // Initialize the cost and root arrays
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                cost[i][j] = 0;
                root[i][j] = -1;
            }
        }

        // Base case: single key (cost is just the probability of that key)
        for (int i = 0; i < n; i++) {
            cost[i][i] = probabilities[i];
            root[i][i] = i;
        }

        // Fill the cost and root tables
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                cost[i][j] = 1e9; // Use a large value to represent infinity

                float sum = 0;
                for (int k = i; k <= j; k++) {
                    sum += probabilities[k];
                }

                for (int r = i; r <= j; r++) {
                    float temp = (r > i ? cost[i][r-1] : 0) + (r < j ? cost[r+1][j] : 0) + sum;
                    if (temp < cost[i][j]) {
                        cost[i][j] = temp;
                        root[i][j] = r;
                    }
                }
            }
        }

        cout << "Minimum Search Cost: " << cost[0][n-1] << endl;

        cout << "Optimal BST Root Positions: " << endl;
        printOptimalBST(root, 0, n-1);
    }

    void printOptimalBST(int **root, int i, int j) {
        if (i > j) return;
        int r = root[i][j];
        cout << "Root: " << keys[r] << endl;
        printOptimalBST(root, i, r-1);
        printOptimalBST(root, r+1, j);
    }

    ~OptimalBST() {
        delete[] keys;
        delete[] probabilities;
    }
};

int main() {
    int n;
    cout << "Enter the number of keys: ";
    cin >> n;

    OptimalBST tree(n);
    tree.input();
    tree.computeOptimalBST();

    return 0;
}
