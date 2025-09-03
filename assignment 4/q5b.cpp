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

};

class Stack{
    Queue q;

public:
    void push(int x) {
        int sz = q.size();
        q.enqueue(x);
        // rotate to bring new element to front
        for (int i = 0; i < sz; i++) {
            q.enqueue(q.dequeue());
        }
    }

    int pop() {
        if (q.isEmpty()) {
            cout << "Stack underflow!" << endl;
            return -1;
        }
        return q.dequeue();
    }

    int top() {
        if (q.isEmpty()) return -1;
        return q.peek();
    }

    bool isEmpty() {
        return q.isEmpty();
    }
};

int main() {
    cout << "Stack using One Queue:\n";
    Stack s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    cout << "Top: " << s1.top() << endl;  // 30
    cout << "Pop: " << s1.pop() << endl;  // 30
    cout << "Pop: " << s1.pop() << endl;  // 20

    return 0;
}
