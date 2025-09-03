#include <iostream>
using namespace std;

int max_size = 100;

class CircularQueue {
    int front, rear;
    int cap;
    int CurrSize;
    int arr[100];

public:
    CircularQueue(int capacity) {
        front = -1;
        rear = -1;
        CurrSize = 0;
        cap = capacity;
    }

    bool isEmpty() {
        return CurrSize == 0;
    }

    bool isFull() {
        return CurrSize == cap;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue overflow!" << x << endl;
            return;
        }
        if (front == -1) front = 0;
        rear = (rear + 1) % cap;
        arr[rear] = x;
        CurrSize++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow! Cannot dequeue" << endl;
            return;
        }
        if(front == rear){// 1 ele
            front = -1;
            rear = -1;
            CurrSize = 0;
            return;
        }
        front = (front + 1) % cap;
        CurrSize--;
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
        int i = front;
        while(true){
            cout << arr[i] << " ";
            if(i == rear)break;
            i = (i + 1)% cap;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue cq(6);

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
                cq.enqueue(x);
                break;
            case 2:
                val = cq.peek();
                cq.dequeue();
                if (val != -1) cout << val << " has been dequeued" << endl;
                break;
            case 3:
                if (cq.isEmpty())
                    cout << "Queue is empty" << endl;
                else
                    cout << "Queue is not empty" << endl;
                break;
            case 4:
                if (cq.isFull())
                    cout << "Queue is full" << endl;
                else
                    cout << "Queue is not full" << endl;
                break;
            case 5:
                cq.Display();
                break;
            case 6:
                val = cq.peek();
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
