#include <iostream>
using namespace std;

int max_size = 100;

class Queue {
    int front, rear;
    int arr[100];

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    bool isFull() {
        return (rear == max_size - 1);
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue overflow! Cannot enqueue " << x << endl;
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = x;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow! Cannot dequeue" << endl;
            return -1;
        }
        int ele = arr[front];
        front++;
        if (front > rear) { 
            front = -1;
            rear = -1;
        }
        return ele;
    }

    int peek() {
        if (!isEmpty()) {
            return arr[front];
        }
        return -1;
    }

    int size() {
        if (isEmpty()) return 0;
        return rear - front + 1;
    }

    void Display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }


    void interleave() {
        int n = size();
        if (n % 2 != 0) {
            cout << "Queue must have even number of elements!" << endl;
            return;
        }

        int half = n / 2;
        Queue firstHalf;


        for (int i = 0; i < half; i++) {
            firstHalf.enqueue(dequeue());
        }

      
        while (!firstHalf.isEmpty()) {
            enqueue(firstHalf.dequeue());
            enqueue(dequeue());     
        }
    }
};

int main() {
    Queue q;
    int n, val;

    cout << "Enter number of elements (even): ";
    cin >> n;

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        q.enqueue(val);
    }

    cout << "Original Queue: ";
    q.Display();

    q.interleave();

    cout << "Interleaved Queue: ";
    q.Display();

    return 0;
}
