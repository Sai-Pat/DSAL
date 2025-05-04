/*Implement all the functions of a dictionary (ADT) using hashing and handle 
collisions using: with replacement method. 
Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be 
comparable, Keys must be unique.  
Standard Operations: Insert(key, value), Find(key), Delete(key)*/
#include <iostream>
#include <string>
#define MAX 10
using namespace std;

class dc {
    string na[MAX];      // names (keys)
    long noa[MAX];       // phone numbers (values)
    int chain[MAX];      // for chaining

public:
    dc() {
        for (int i = 0; i < MAX; i++) {
            na[i] = "";
            noa[i] = 0;
            chain[i] = -1;
        }
    }

    int hashFunction(string key) {
        return key.length() % MAX;
    }

    void insert() {
        string name;
        long phone;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Phone: ";
        cin >> phone;

        int index = hashFunction(name);

        // If the position is empty, insert directly
        if (na[index] == "") {
            na[index] = name;
            noa[index] = phone;
            return;
        }

        // Check if current occupant belongs to a different hash (replacement needed)
        int currentHash = hashFunction(na[index]);
        if (currentHash != index) {
            // Find a free spot
            int freeIndex = -1;
            for (int i = 0; i < MAX; i++) {
                if (na[i] == "") {
                    freeIndex = i;
                    break;
                }
            }

            if (freeIndex == -1) {
                cout << "Hash table is full.\n";
                return;
            }

            // Move existing record to freeIndex
            na[freeIndex] = na[index];
            noa[freeIndex] = noa[index];
            chain[freeIndex] = chain[index];

            // Fix chains pointing to old index
            for (int i = 0; i < MAX; i++) {
                if (chain[i] == index) {
                    chain[i] = freeIndex;
                    break;
                }
            }

            chain[index] = -1; // reset original chain

            // Place new key at correct hash index
            na[index] = name;
            noa[index] = phone;

            return;
        }

        // Chaining needed: find next free slot
        int freeIndex = -1;
        for (int i = 0; i < MAX; i++) {
            if (na[i] == "") {
                freeIndex = i;
                break;
            }
        }

        if (freeIndex == -1) {
            cout << "Hash table is full.\n";
            return;
        }

        // Insert at free index and chain
        na[freeIndex] = name;
        noa[freeIndex] = phone;

        // Find end of chain
        int temp = index;
        while (chain[temp] != -1) {
            temp = chain[temp];
        }
        chain[temp] = freeIndex;
    }

    void find() {
        string name;
        cout << "Enter Name to Find: ";
        cin >> name;

        int index = hashFunction(name);
        while (index != -1) {
            if (na[index] == name) {
                cout << "Found! Name: " << na[index] << ", Phone: " << noa[index] << "\n";
                return;
            }
            index = chain[index];
        }

        cout << "Record not found.\n";
    }

    void del() {
        string name;
        cout << "Enter Name to Delete: ";
        cin >> name;

        int index = hashFunction(name);
        int prev = -1;

        while (index != -1) {
            if (na[index] == name) {
                // Clear record
                na[index] = "";
                noa[index] = 0;

                if (prev != -1) {
                    chain[prev] = chain[index];
                }
                chain[index] = -1;

                cout << "Record Deleted.\n";
                return;
            }

            prev = index;
            index = chain[index];
        }

        cout << "Record not found.\n";
    }

    void display() {
        cout << "\nIndex\tName\tPhone\tChain\n";
        for (int i = 0; i < MAX; i++) {
            cout << i << "\t" << na[i] << "\t" << noa[i] << "\t" << chain[i] << "\n";
        }
    }
};

int main() {
    dc d;
    int choice;

    do {
        cout << "\n--- Dictionary Menu ---\n";
        cout << "1. Insert\n2. Find\n3. Delete\n4. Display\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: d.insert(); break;
        case 2: d.find(); break;
        case 3: d.del(); break;
        case 4: d.display(); break;
        case 5: break;
        default: cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}
