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
            cout << "Queue overflow!" << x << endl;
            return;
        }
        if (front == -1) front = 0;
        rear++;
        arr[rear] = x;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow! Cannot dequeue" << endl;
            return;
        }
        front++;
        return;
    }

    int peek() {
        if (!isEmpty()) {
            return arr[front];
        }
        return -1;
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
};

int main() {
    Queue q;

    while (true) {
        int num;
        cout << "\nPlease enter the operation you want to perform with queue :" << endl;
        cout << "1 for enqueue" << endl;
        cout << "2 for dequeue" << endl;
        cout << "3 for isEmpty" << endl;
        cout << "4 for isFull" << endl;
        cout << "5 for display" << endl;
        cout << "6 for peek" << endl;
        cin >> num;

        int x, val;
        switch (num) {
            case 1:
                cout << "Enter element to enqueue: ";
                cin >> x;
                q.enqueue(x);
                break;
            case 2:
                val = q.peek();
                q.dequeue();
                if (val != -1) cout << val << " has been dequeued" << endl;
                break;
            case 3:
                if (q.isEmpty())
                    cout << "Queue is empty" << endl;
                else
                    cout << "Queue is not empty" << endl;
                break;
            case 4:
                if (q.isFull())
                    cout << "Queue is full" << endl;
                else
                    cout << "Queue is not full" << endl;
                break;
            case 5:
                q.Display();
                break;
            case 6:
                val = q.peek();
                if (val != -1)
                    cout << "Front element is " << val << endl;
                else
                    cout << "Queue is empty" << endl;
                break;
            default:
                cout << "Invalid Operation." << endl;
                break;
        }

        char ch;
        cout << "Press 'y' if you want to continue, any other key to discontinue: ";
        cin >> ch;
        if (ch != 'y') {
            break;
        }
    }

    return 0;
}
