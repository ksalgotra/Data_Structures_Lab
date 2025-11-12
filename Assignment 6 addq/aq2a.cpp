#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int d) : data(d), prev(NULL), next(NULL) {}
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
    if (head == NULL)
        return newNode;

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
    return head;
}


void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


Node* removeEvenParityNodes(Node* head) {
    Node* current = head;
    while (current != NULL) {
        if (hasEvenParity(current->data)) {
            Node* temp = current;

            if (current->prev != NULL)
                current->prev->next = current->next;
            else
                head = current->next;

            if (current->next != NULL)
                current->next->prev = current->prev;

            current = current->next;
            delete temp;
        } else {
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

    cout << "Original Doubly Linked List: ";
    display(head);

    head = removeEvenParityNodes(head);

    cout << "After removing even-parity nodes: ";
    display(head);

    return 0;
}
