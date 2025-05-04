/*A book consists of chapters, chapters consist of sections and sections consist of 
subsections. Construct a tree and print the nodes. Find the time and space 
requirements of your method.*/
#include<iostream>
using namespace std;

// Subsection node
struct Subsection {
    string title;
    Subsection* next;
};

// Section node
struct Section {
    string title;
    Subsection* subHead;  // Points to first subsection
    Section* next;
};

// Chapter node
struct Chapter {
    string title;
    Section* secHead;  // Points to first section
    Chapter* next;
};

// Book node
struct Book {
    string title;
    Chapter* chHead;  // Points to first chapter

    // Function to input data
    void createBook() {
        cout << "Enter book title: ";
        getline(cin, title);
        chHead = NULL;

        int chCount;
        cout << "Enter number of chapters: ";
        cin >> chCount;
        cin.ignore();  // To ignore the newline character after integer input

        Chapter* lastCh = NULL;
        for (int i = 0; i < chCount; i++) {
            Chapter* ch = new Chapter;
            cout << "Enter chapter " << i + 1 << " title: ";
            cin >> ch->title;
            ch->secHead = NULL;
            ch->next = NULL;

            if (chHead == NULL) chHead = ch;
            else lastCh->next = ch;
            lastCh = ch;

            int secCount;
            cout << "  Enter number of sections: ";
            cin >> secCount;
            cin.ignore();

            Section* lastSec = NULL;
            for (int j = 0; j < secCount; j++) {
                Section* sec = new Section;
                cout << "  Enter section " << j + 1 << " title: ";
                cin >> sec->title;
                sec->subHead = NULL;
                sec->next = NULL;

                if (ch->secHead == NULL) ch->secHead = sec;
                else lastSec->next = sec;
                lastSec = sec;

                int subCount;
                cout << "    Enter number of subsections: ";
                cin >> subCount;
                cin.ignore();

                Subsection* lastSub = NULL;
                for (int k = 0; k < subCount; k++) {
                    Subsection* sub = new Subsection;
                    cout << "    Enter subsection " << k + 1 << " title: ";
                    cin >> sub->title;
                    sub->next = NULL;

                    if (sec->subHead == NULL) sec->subHead = sub;
                    else lastSub->next = sub;
                    lastSub = sub;
                }
            }
        }
    }

    // Function to print the book structure
    void printBook() {
        cout << "\nBook: " << title << endl;
        Chapter* ch = chHead;
        while (ch != NULL) {
            cout << "  Chapter: " << ch->title << endl;
            Section* sec = ch->secHead;
            while (sec != NULL) {
                cout << "    Section: " << sec->title << endl;
                Subsection* sub = sec->subHead;
                while (sub != NULL) {
                    cout << "      Subsection: " << sub->title << endl;
                    sub = sub->next;
                }
                sec = sec->next;
            }
            ch = ch->next;
        }
    }
};

int main() {
    Book b;
    b.createBook();
    b.printBook();
    return 0;
}
