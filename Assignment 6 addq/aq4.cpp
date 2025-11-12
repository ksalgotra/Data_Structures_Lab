#include <iostream>
#include <unordered_set>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int d) {
        data = d;
        next = prev = NULL;
    }
};

class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() {
        head = NULL;
    }

    void appendNode(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    void print() {
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next)
                cout << " <-> ";
            temp = temp->next;
        }
        cout << " <-> NULL" << endl;
    }

    void printReverse() {
        if (!head) return;
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        while (temp) {
            cout << temp->data;
            if (temp->prev)
                cout << " <-> ";
            temp = temp->prev;
        }
        cout << " <-> NULL" << endl;
    }

    void correctDoublyLinkedList() {
        if (!head) return;

        unordered_set<Node*> visited;
        Node* curr = head;
        Node* prev = NULL;

        while (curr && !visited.count(curr)) {
            visited.insert(curr);

            if (curr->prev != prev)
                curr->prev = prev;

            if (prev && prev->next != curr)
                prev->next = curr;

            prev = curr;
            curr = curr->next;
        }

        if (prev)
            prev->next = NULL;
    }
};

int main() {
    DoublyLinkedList dll;

    dll.appendNode(1);
    dll.appendNode(2);
    dll.appendNode(3);
    dll.appendNode(4);

    
    dll.head->next->next->prev = dll.head;       
    dll.head->next->next->next->next = dll.head; 

    cout << "Attempting to repair doubly linked list...\n\n";

    dll.correctDoublyLinkedList();

    cout << "Corrected Doubly Linked List (Forward):\n";
    dll.print();

    cout << "Corrected Doubly Linked List (Reverse):\n";
    dll.printReverse();

    return 0;
}
