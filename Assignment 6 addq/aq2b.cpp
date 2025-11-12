#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(NULL) {}
};


bool hasEvenParity(int num) {
    int count = 0;
    while (num) {
        if (num & 1)
            count++;
        num >>= 1;
    }
    return (count % 2 == 0);
}


Node* insertEnd(Node* head, int data) {
    Node* newNode = new Node(data);
    if (head == NULL) {
        newNode->next = newNode;  
        return newNode;
    }

    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
    return head;
}


void display(Node* head) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}


Node* removeEvenParityNodes(Node* head) {
    if (head == NULL)
        return NULL;

    Node* current = head;
    Node* prev = NULL;

  
    while (hasEvenParity(head->data)) {
        if (head->next == head) {  
            delete head;
            return NULL;
        }

        Node* last = head;
        while (last->next != head)
            last = last->next;

        Node* temp = head;
        head = head->next;
        last->next = head;
        delete temp;

        if (!hasEvenParity(head->data))
            break;
    }

    prev = head;
    current = head->next;

    while (current != head) {
        if (hasEvenParity(current->data)) {
            Node* temp = current;
            prev->next = current->next;
            current = current->next;
            delete temp;
        } else {
            prev = current;
            current = current->next;
        }
    }

    return head;
}


int main() {
    Node* head = NULL;

    head = insertEnd(head, 10);
    head = insertEnd(head, 7);
    head = insertEnd(head, 5);
    head = insertEnd(head, 15);
    head = insertEnd(head, 8);

    cout << "Original Circular Singly Linked List: ";
    display(head);

    head = removeEvenParityNodes(head);

    cout << "After removing even-parity nodes: ";
    display(head);

    return 0;
}
