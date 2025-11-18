#include <iostream>
using namespace std;

class PriorityQueue {
    int A[100];
    int heap_size;

    int PARENT(int i) { return i / 2; }
    int LEFT(int i) { return 2 * i; }
    int RIGHT(int i) { return 2 * i + 1; }

    void MAX_HEAPIFY(int i) {
        int l = LEFT(i), r = RIGHT(i), largest = i;
        if (l <= heap_size && A[l] > A[largest]) largest = l;
        if (r <= heap_size && A[r] > A[largest]) largest = r;
        if (largest != i) {
            swap(A[i], A[largest]);
            MAX_HEAPIFY(largest);
        }
    }

public:
    PriorityQueue() { heap_size = 0; }

    void insert(int key) {
        heap_size++;
        A[heap_size] = key;
        int i = heap_size;
        while(i > 1 && A[PARENT(i)] < A[i]) {
            swap(A[i], A[PARENT(i)]);
            i = PARENT(i);
        }
    }

    int remove() {
        if (heap_size < 1) return -1;
        int maxVal = A[1];
        A[1] = A[heap_size];
        heap_size--;
        MAX_HEAPIFY(1);
        return maxVal;
    }

    void display() {
        for (int i = 1; i <= heap_size; i++)
            cout << A[i] << " ";
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;
    int n, x;

    cout << "Enter number of elements to insert: ";
    cin >> n;

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++){
        cin >> x;
        pq.insert(x);
    }

    cout << "Priority Queue: ";
    pq.display();

    cout << "Deleted Max: " << pq.remove() << endl;

    cout << "After Deletion: ";
    pq.display();
}
