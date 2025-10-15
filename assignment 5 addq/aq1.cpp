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

Node* findIntersection(Node* head1, Node* head2){
    Node* temp1 = head1;
    Node* temp2 = head2;
    unordered_set<Node*> s;
    while(temp1){
        s.insert(temp1);
        temp1 = temp1->next;
    }
    while(temp2){
        if(s.find(temp2) != s.end()){
            return temp2;
        }
        temp2 = temp2->next;
    }
    return NULL;

}
int main() {
    Node* intersectNode = new Node(8);
    intersectNode->next = new Node(5);
  
    LinkedList listA;
    listA.insertAtEnd(4);
    listA.insertAtEnd(1);
    Node* tempA = listA.head;
    while (tempA->next != NULL) tempA = tempA->next;
    tempA->next = intersectNode; 
  
    LinkedList listB;
    listB.insertAtEnd(5);
    listB.insertAtEnd(6);
    listB.insertAtEnd(1);
    Node* tempB = listB.head;
    while (tempB->next != NULL) tempB = tempB->next;
    tempB->next = intersectNode;  


    cout << "List A: ";
    listA.display();
    cout << "List B: ";
    listB.display();

 
    Node* ans = findIntersection(listA.head, listB.head);

    if (ans)
        cout << "Intersected at " << ans->val << endl;
    else
        cout << "No intersection" << endl;

    return 0;
}
