/*Construct an expression tree from the given prefix expression eg. +- -a*bc/def and 
traverse it using post order traversal (non-recursive) and then delete the entire 
tree. */
#include<iostream>
#include<stack>
#include<string>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
    
    Node(char val) : data(val), left(NULL), right(NULL) {}
};

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

Node* constructTree(string prefix) {
    stack<Node*> st;
    
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char current = prefix[i];
        
        if (isOperator(current)) {
            Node* node = new Node(current);
            node->left = st.top(); st.pop();
            node->right = st.top(); st.pop();
            st.push(node);
        } else {
            st.push(new Node(current));
        }
    }
    
    return st.top();
}

void postOrderTraversal(Node* root) {
    if (!root) return;
    
    stack<Node*> st1, st2;
    st1.push(root);
    
    while (!st1.empty()) {
        Node* node = st1.top();
        st1.pop();
        st2.push(node);
        
        if (node->left) st1.push(node->left);
        if (node->right) st1.push(node->right);
    }
    
    while (!st2.empty()) {
        cout << st2.top()->data << " ";
        st2.pop();
    }
}

void deleteTree(Node* root) {
    if (!root) return;
    
    deleteTree(root->left);
    deleteTree(root->right);
    
    delete root;
}

int main() {
    string prefix = "+- -a*bc/def";
    
    Node* root = constructTree(prefix);
    
    cout << "Post-order traversal of the expression tree: ";
    postOrderTraversal(root);
    cout << endl;
    
    deleteTree(root);
    
    return 0;
}
