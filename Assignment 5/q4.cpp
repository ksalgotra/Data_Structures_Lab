# include<iostream>
using namespace std;

class Node{
public:
    int val;
    Node* next;

    Node(int val){
        this->val = val;
        next = NULL;
    }
};
class LinkedList{
public:
    Node* head;

    LinkedList(){
        head = NULL;
    }
    void insertAtEnd(int x){
        Node* newNode = new Node(x);
        if(head == NULL){
            head = newNode;
        }
        else{
            Node* temp = head;
            while(temp->next){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void display(){
        Node* temp = head;
        while(temp){
            cout << temp->val << "->";
            temp = temp->next;
        }
        cout<<"NULL" << endl;
    }

};

Node* reverseLL(Node* head){
    Node* curr = head;
    Node* next = NULL;
    Node* prev = NULL;

    while(curr){
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }

    return prev;
}
int main(){
    LinkedList ll;
    ll.insertAtEnd(1);
    ll.insertAtEnd(2);
    ll.insertAtEnd(3);
    ll.insertAtEnd(4);
    ll.insertAtEnd(5);
    
    ll.display();

    ll.head = reverseLL(ll.head);
    ll.display();

    return 0;
    
}
