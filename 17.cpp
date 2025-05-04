#include <iostream>
using namespace std;

void heapify(int a[], int n, int i, bool maxHeap) {
    int ext = i, l = 2*i+1, r = 2*i+2;
    if (l < n && ((maxHeap && a[l] > a[ext]) || (!maxHeap && a[l] < a[ext]))) ext = l;
    if (r < n && ((maxHeap && a[r] > a[ext]) || (!maxHeap && a[r] < a[ext]))) ext = r;
    if (ext != i) {
        swap(a[i], a[ext]);
        heapify(a, n, ext, maxHeap);
    }
}

void buildHeap(int a[], int n, bool maxHeap) {
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(a, n, i, maxHeap);
}

int main() {
    int n, a[100];
    cout << "Enter number of students: ";
    cin >> n;
    cout << "Enter marks: ";
    for (int i = 0; i < n; i++) cin >> a[i];

    buildHeap(a, n, true);  // max-heap
    cout << "Max Marks = " << a[0] << endl;

    buildHeap(a, n, false); // min-heap
    cout << "Min Marks = " << a[0] << endl;
}
