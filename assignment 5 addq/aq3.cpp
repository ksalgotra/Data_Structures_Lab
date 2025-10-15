# include<iostream>
# include<unordered_set>
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
        int count = 0;
        Node* temp = head;
        while(temp && count < 10){
            cout << temp->val << "->";
            temp = temp->next;
            count++;
        }
        cout<<"NULL" << endl;
    }

};

Node* removeLoop(Node* head){
    if(!head || !head->next)return head;
    
    Node* slow = head;
    Node* fast = head;
    
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            break;
        }
    }

    if(slow != fast){
        return head;
    }

    slow = head;

    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }

    Node* loopEnd = fast;
    while (loopEnd->next != fast) {
        loopEnd = loopEnd->next;
    }
    loopEnd->next = NULL;
    return head;
}

int main(){
    LinkedList ll;
    ll.insertAtEnd(10);
    ll.insertAtEnd(20);
    ll.insertAtEnd(30);
    ll.insertAtEnd(40);
    ll.insertAtEnd(50);

    cout << "Original List: ";
    ll.display();

    ll.head->next->next->next->next->next = ll.head->next->next;
    
    ll.head = removeLoop(ll.head);
    ll.display();
}
