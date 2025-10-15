# include<iostream>
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

};

pair<Node*, Node*> twoCLLs(Node* head){
    if (!head || head->next == head) return {head, NULL};
    Node* slow = head;
    Node* fast = head;

    while(fast->next != head && fast->next->next != head){
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* head1 = head;
    Node* head2 = slow->next;

    slow->next = head1;

    if(fast->next->next == head){
        fast = fast->next;
    }
    fast->next = head2;

    return {head1, head2};
    
}

void display(Node* head) {
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


int main() {
    CircularLinkedList cll;
    cll.insertAtEnd(20);
    cll.insertAtEnd(100);
    cll.insertAtEnd(40);
    cll.insertAtEnd(80);
    cll.insertAtEnd(60);


    cout << "Circular Linked List: ";
    display(cll.head);
    pair<Node*, Node*> clls = twoCLLs(cll.head);
    Node* head1 = clls.first;
    Node* head2 = clls.second;
    display(head1);
    display(head2);

    return 0;
}
