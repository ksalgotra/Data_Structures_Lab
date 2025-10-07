# include<iostream>
# include<list>
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

};

Node* findMiddle(Node* head1){
    Node* slow = head1;
    Node* fast = head1;
    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main(){
    LinkedList ll;
    ll.insertAtEnd(1);
    ll.insertAtEnd(2);
    ll.insertAtEnd(3);
    ll.insertAtEnd(4);
    ll.insertAtEnd(5);

    Node* middle = findMiddle(ll.head);
    cout << "Middle is :" << middle->val << endl;
    
}
