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

class LinkedList {
public:
    Node* head;
    LinkedList() {
        head = NULL;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    bool isCircular() {
        if (!head) return false; 

        Node* temp = head->next;
        while (temp != NULL && temp != head) {
            temp = temp->next;
        }

        return (temp == head); 
    }

    void displayList(int n) { // using n to prevent infinte loop if list is circular
        Node* temp = head;
        int count = 0;
        while (temp != NULL && count < n) {
            cout << temp->data << " -> ";
            temp = temp->next;
            count++;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList ll;

    ll.insertAtEnd(10);
    ll.insertAtEnd(20);
    ll.insertAtEnd(30);
    ll.insertAtEnd(40);

    if (ll.isCircular())
        cout << "The linked list is circular.\n";
    else
        cout << "The linked list is not circular.\n";

    ll.head->next->next->next->next = ll.head;// circular LL

    ll.displayList(8);

    if (ll.isCircular())
        cout << "The linked list is circular.\n";
    else
        cout << "The linked list is not circular.\n";

    return 0;
}
