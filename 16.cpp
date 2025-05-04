#include <iostream>
#include <cstring>
using namespace std;

class Node {
public:
    char word[50];
    char meaning[100];
    Node *left, *right;
    int height;
    Node(const char *w, const char *m) {
        strcpy(word, w);
        strcpy(meaning, m);
        left = NULL;
        right = NULL;
        height = 1;
    }
};

int height(Node *n) {
    if (n == NULL)
        return 0;
    else
        return n->height;
}

int getBalance(Node *n) {
    if (n == NULL)
        return 0;
    else
        return height(n->left) - height(n->right);
}

int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

Node* rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

Node* insert(Node *root, const char *w, const char *m) {
    if (root == NULL) {
        return new Node(w, m);
    }

    if (strcmp(w, root->word) < 0) {
        root->left = insert(root->left, w, m);
    }
    else if (strcmp(w, root->word) > 0) {
        root->right = insert(root->right, w, m);
    }
    else {
        return root; // Duplicate keys not allowed
    }

    root->height = max(height(root->left), height(root->right)) + 1;
    int balance = getBalance(root);

    // Left Left
    if (balance > 1 && strcmp(w, root->left->word) < 0)
        return rightRotate(root);

    // Right Right
    if (balance < -1 && strcmp(w, root->right->word) > 0)
        return leftRotate(root);

    // Left Right
    if (balance > 1 && strcmp(w, root->left->word) > 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left
    if (balance < -1 && strcmp(w, root->right->word) < 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inorder(Node *root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->word << " : " << root->meaning << endl;
        inorder(root->right);
    }
}

int search(Node *root, const char *key, int &count) {
    if (root == NULL)
        return 0;

    count++;
    if (strcmp(key, root->word) == 0)
        return 1;
    else if (strcmp(key, root->word) < 0)
        return search(root->left, key, count);
    else
        return search(root->right, key, count);
}

int main() {
    Node *root = NULL;

    root = insert(root, "apple", "a fruit");
    root = insert(root, "book", "something to read");
    root = insert(root, "zebra", "a wild animal");
    root = insert(root, "cat", "a pet");

    cout << "\nDictionary (Ascending Order):\n";
    inorder(root);

    int count = 0;
    char key[50];
    cout << "\nEnter word to search: ";
    cin >> key;
    if (search(root, key, count) == 1)
        cout << "Found in " << count << " comparisons.\n";
    else
        cout << "Not found. Comparisons: " << count << endl;

    cout << "\nMax comparisons (height): " << height(root) << endl;

    return 0;
}
