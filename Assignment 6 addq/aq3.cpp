#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data) {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};



void reverseDLL(Node* start, Node* end) {
    Node* curr = start;
    Node* temp = NULL;
    Node* stop = end->next; 

    while (curr != stop) {
       
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;

        curr = curr->prev;
    }
}



Node* reverseInGroups(Node* head, int k) {
    if (!head || k <= 1)
        return head;

    Node* start = head;
    Node* end = head;
    Node* prevGroupEnd = NULL;
    Node* newHead = NULL;
    int count = 1;

    while (end) {
        if (count % k == 0) {
            Node* nextGroupStart = end->next;

      
            reverseDLL(start, end);

            // If this is the first group, set new head
            if (newHead == NULL)
                newHead = end;

            if (prevGroupEnd) {
                prevGroupEnd->next = end;
                end->prev = prevGroupEnd;  
            } else {
                end->prev = NULL; 
            }

            start->next = nextGroupStart;
            if (nextGroupStart)
                nextGroupStart->prev = start;


            prevGroupEnd = start;
            start = nextGroupStart;
            end = nextGroupStart;
        } else {
            end = end->next;
        }
        count++;
    }

    if (newHead == NULL)
        newHead = head;

    return newHead;
}


Node* insertEnd(Node* head, int data) {
    Node* newNode = new Node(data);
    if (!head)
        return newNode;

    Node* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

void display(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next)
            cout << " <-> ";
        temp = temp->next;
    }
    cout << " <-> NULL" << endl;
}


int main() {
    Node* head = NULL;

    head = insertEnd(head, 1);
    head = insertEnd(head, 2);
    head = insertEnd(head, 3);
    head = insertEnd(head, 4);
    head = insertEnd(head, 5);
    head = insertEnd(head, 6);

    int k = 2;

    cout << "Original Doubly Linked List:\n";
    display(head);

    head = reverseInGroups(head, k);

    cout << "Reversed in groups of " << k << ":\n";
    display(head);

    return 0;
}
