#include <iostream>
using namespace std;

int max_size = 100;

class Queue {
    int front, rear;
    char arr[100];

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

    void enqueue(char x) {
        if (isFull()) {
            cout << "Queue overflow! Cannot enqueue " << x << endl;
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = x;
    }

    char dequeue() {
        if (isEmpty()) {
            return '\0';
        }
        char ele = arr[front];
        front++;
        if (front > rear) { // queue empty
            front = -1;
            rear = -1;
        }
        return ele;
    }

    char peek() {
        if (!isEmpty()) {
            return arr[front];
        }
        return '\0';
    }
};

void firstNonRepeating(string s){
    Queue q;
    int freq[26] = {0};

    for(char ch : s){
        if(ch == ' ')continue;

        q.enqueue(ch);
        freq[ch - 'a']++;

        while(!q.isEmpty() && freq[q.peek() - 'a'] > 1){
            q.dequeue();
        }

        if (q.isEmpty()) {
            cout << -1 << " ";
        } else {
            cout << q.peek() << " ";
        }
    }
    cout << endl;
}

int main() {
    string s;
    cout << "Enter the string: ";
    getline(cin, s);

    cout << "Output: ";
    firstNonRepeating(s);

    return 0;
}
