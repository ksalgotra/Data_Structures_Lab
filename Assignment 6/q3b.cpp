#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class CircularLinkedList {
public:
    Node* head;
    CircularLinkedList() {
        head = NULL;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            head->next = head;
        }
        else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            newNode->next = temp->next; 
            temp->next = newNode;
        }
    }

    void display() {
        if (!head) {
            cout << "Empty CLL" << endl;
            return;
        }
        Node* temp = head;
        while (temp->next != head) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << temp->data << "->";
        cout << temp->next->data << endl; 
    }

    int getSize() {
        if (!head) {
            return 0;
        }
        int size = 0;
        Node* temp = head;
        do {
            size++;
            temp = temp->next;
        } while (temp != head); 
        return size;
    }
};

int main() {
    CircularLinkedList cll;
    cll.insertAtEnd(20);
    cll.insertAtEnd(100);
    cll.insertAtEnd(40);
    cll.insertAtEnd(80);
    cll.insertAtEnd(60);


    cout << "Circular Linked List: ";
    cll.display();
    cout << "Size of Circular Linked List: " << cll.getSize() << endl;

    return 0;
}
