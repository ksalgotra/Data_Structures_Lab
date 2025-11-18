#include <iostream>
using namespace std;

int heap_size;

void MAX_HEAPIFY(int A[], int i) {
    int l = 2*i;
    int r = 2*i + 1;
    int largest = i;

    if (l <= heap_size && A[l] > A[largest])
        largest = l;
    if (r <= heap_size && A[r] > A[largest])
        largest = r;

    if (largest != i) {
        swap(A[i], A[largest]);
        MAX_HEAPIFY(A, largest);
    }
}

void BUILD_MAX_HEAP(int A[], int n) {
    heap_size = n;
    for (int i = n/2; i >= 1; i--)
        MAX_HEAPIFY(A, i);
}

void HEAPSORT(int A[], int n) {
    BUILD_MAX_HEAP(A, n);
    for (int i = n; i >= 2; i--) {
        swap(A[1], A[i]);
        heap_size--;
        MAX_HEAPIFY(A, 1);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int A[n+1];
    cout << "Enter elements: ";
    for(int i = 1; i <= n; i++)
        cin >> A[i];

    HEAPSORT(A, n);

    cout << "Sorted Array: ";
    for(int i = 1; i <= n; i++)
        cout << A[i] << " ";
    cout << endl;
}
