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
    Queue q1;
    Queue q2;
public:

    void push(int x){
        if(q1.isFull()){
            cout << "Max capacity" << endl;
            return;
        }
        q1.enqueue(x);
    }

    int pop(){
        if(q1.isEmpty()){
            cout << "Stack is Empty" << endl;
        }
        while (q1.size() > 1) {
            q2.enqueue(q1.dequeue());
        }

        int popped = q1.dequeue();

        Queue temp = q1;
        q1 = q2;
        q2 = temp;

        return popped;
    }

    int top() {
        if (q1.isEmpty()) return -1;

        while (q1.size() > 1) {
            q2.enqueue(q1.dequeue());
        }

        int topEle = q1.peek();
        q2.enqueue(q1.dequeue());

        Queue temp = q1;
        q1 = q2;
        q2 = temp;

        return topEle;
    }

    bool isEmpty() {
        return q1.isEmpty();
    }
};

int main() {
    cout << "Stack using Two Queues:\n";
    Stack s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    cout << "Top: " << s1.top() << endl;  // 30
    cout << "Pop: " << s1.pop() << endl;  // 30
    cout << "Pop: " << s1.pop() << endl;  // 20

    return 0;
}
