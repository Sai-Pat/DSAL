/*
Beginning with an empty binary search tree, Construct binary search tree by 
inserting the values in the order given. After constructing a binary tree - 
  i. Insert new node 
 ii. Find number of nodes in longest path from root  
iii. Minimum data value found in the tree 
*/
#include<iostream>
#include<algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class BST {
    public:
        Node* root;

        BST() {
            root = NULL;
        }

        Node* insert(Node* root, int value) {
            if (root == NULL) {
                return new Node(value);
            }
            if (value < root->data) {
                root->left = insert(root->left, value);
            } else {
                root->right = insert(root->right, value);
            }
            return root;
        }

        void insert(int value) {
            root = insert(root, value);
        }

        int longestPath(Node* root) {
            if (root == NULL) return 0;
            int leftHeight = longestPath(root->left);
            int rightHeight = longestPath(root->right);
            return max(leftHeight, rightHeight) + 1;
        }

        int findLongestPath() {
            return longestPath(root);
        }

        int findMin(Node* root) {
            if (root == NULL) return -1;  // Tree is empty
            while (root->left != NULL) {
                root = root->left;
            }
            return root->data;
        }

        int findMinValue() {
            return findMin(root);
        }
};

int main() {
    BST tree;

    // Insert nodes into the BST
    int values[] = {50, 30, 20, 40, 70, 60, 80};
    for (int i = 0; i < 7; i++) {
        tree.insert(values[i]);
    }

    // Insert a new node
    cout << "Inserting 25 into the BST" << endl;
    tree.insert(25);

    // Find number of nodes in the longest path (height + 1)
    cout << "Longest path (number of nodes) from root: " << tree.findLongestPath() << endl;

    // Find the minimum data value in the tree
    cout << "Minimum value in the tree: " << tree.findMinValue() << endl;

    return 0;
}
