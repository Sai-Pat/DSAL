/*Beginning with an empty binary search tree, Construct binary search tree by 
inserting the values in the order given. After constructing a binary tree - 
i.   Insert new node  
ii.  Search a specific value in a tree   
iii. Change a tree so that the roles of the left and right pointers are swapped at 
every node.*/
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(NULL), right(NULL) {}
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

    bool search(Node* root, int value) {
        if (root == NULL) return false;
        if (root->data == value) return true;
        if (value < root->data) return search(root->left, value);
        return search(root->right, value);
    }

    bool search(int value) {
        return search(root, value);
    }

    void swapSubtrees(Node* root) {
        if (root == NULL) return;
        swap(root->left, root->right);
        swapSubtrees(root->left);
        swapSubtrees(root->right);
    }

    void inorder(Node* root) {
        if (root == NULL) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void inorder() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    BST tree;

    int values[] = {50, 30, 20, 40, 70, 60, 80};
    for (int i = 0; i < 7; i++) {
        tree.insert(values[i]);
    }

    cout << "Inorder traversal of the original tree: ";
    tree.inorder();

    cout << "Inserting 25 into the BST." << endl;
    tree.insert(25);
    cout << "Inorder traversal after inserting 25: ";
    tree.inorder();

    int valueToSearch = 40;
    if (tree.search(valueToSearch)) {
        cout << valueToSearch << " is found in the tree." << endl;
    } else {
        cout << valueToSearch << " is not found in the tree." << endl;
    }

    cout << "Swapping left and right subtrees at every node." << endl;
    tree.swapSubtrees(tree.root);
    cout << "Inorder traversal after swapping subtrees: ";
    tree.inorder();

    return 0;
}
