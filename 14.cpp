#include <iostream>
#include <cstring>
using namespace std;

const int SIZE = 10;

class Node {
public:
    char key[50];
    long value;
    Node* next;
    Node(const char* k, long v) {
        strcpy(key, k);
        value = v;
        next = NULL;
    }
};

class HashTable {
public:
    Node* table[SIZE];

    HashTable() {
        for (int i = 0; i < SIZE; i++)
            table[i] = NULL;
    }

    int hash(const char* key) {
        int hashVal = 0;
        int p = 31; // prime multiplier
        for (int i = 0; key[i] != '\0'; i++)
            hashVal = (hashVal * p + key[i]) % SIZE;
        return hashVal;
    }

    void insert(const char* key, long value) {
        int index = hash(key);
        Node* temp = table[index];

        while (temp != NULL) {
            if (strcmp(temp->key, key) == 0) {
                cout << "Key already exists.\n";
                return;
            }
            temp = temp->next;
        }

        Node* newNode = new Node(key, value);
        newNode->next = table[index];
        table[index] = newNode;
    }

    void find(const char* key) {
        int index = hash(key);
        Node* temp = table[index];

        while (temp != NULL) {
            if (strcmp(temp->key, key) == 0) {
                cout << "Found: " << temp->key << " -> " << temp->value << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Key not found.\n";
    }

    void remove(const char* key) {
        int index = hash(key);
        Node* curr = table[index];
        Node* prev = NULL;

        while (curr != NULL) {
            if (strcmp(curr->key, key) == 0) {
                if (prev == NULL)
                    table[index] = curr->next;
                else
                    prev->next = curr->next;
                delete curr;
                cout << "Key deleted.\n";
                return;
            }
            prev = curr;
            curr = curr->next;
        }
        cout << "Key not found.\n";
    }

    void display() {
        for (int i = 0; i < SIZE; i++) {
            cout << i << " -> ";
            Node* temp = table[i];
            while (temp != NULL) {
                cout << "[" << temp->key << ": " << temp->value << "] -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    HashTable dict;
    dict.insert("apple", 101);
    dict.insert("book", 202);
    dict.insert("pen", 303);
    dict.insert("zebra", 404);

    dict.display();

    dict.find("pen");
    dict.remove("book");
    dict.display();

    return 0;
}
