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
        Node* temp = head;
        while(temp){
            cout << temp->val << "->";
            temp = temp->next;
        }
        cout<<"NULL" << endl;
    }

};

Node* rotateLeftBykNodes(Node* head, int k) {
    if (!head || k == 0) return head;

    
    Node* tail = head;
    int n = 1;
    while (tail->next) {
        tail = tail->next;
        n++;
    }
    tail->next = head;

 
    k = k % n;
    Node* newTail = head;
    for (int i = 0; i < k - 1; i++) {
        newTail = newTail->next;
    }
    Node* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
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

    int k = 4;
    ll.head = rotateLeftBykNodes(ll.head, k);

    cout << "After left rotating by " << k << ": ";
    ll.display();

    return 0;
}
