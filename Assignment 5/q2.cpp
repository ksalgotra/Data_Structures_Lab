# include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

class LinkedList{
public:
    Node* head;
    LinkedList(){
        head = NULL;
    }
    Node* gethead(){
        return head;
    }
    void insertAtBeginning(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    cout << "Inserted " << value << " at the beginning.\n";
    }

void insertAtEnd(int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
        cout << "Inserted " << value << " as the first node.\n";
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    cout << "Inserted " << value << " at the end.\n";
}

void insertBefore(int key, int value) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }

  
    if (head->data == key) {
        insertAtBeginning(value);
        return;
    }

    Node* temp = head; 
    while (temp->next && temp->next->data != key) {
        temp = temp->next;
    }

    if (temp->next) {
        Node* newNode = new Node(value);
        newNode->next = temp->next; 
        temp->next = newNode;
        cout << "Inserted " << value << " before " << key << ".\n";
    } else {
        cout << "Key " << key << " not found.\n";
    }
}


void insertAfter(int key, int value) {
    Node* temp = head;
    while (temp && temp->data != key) {
        temp = temp->next;
    }
    if (temp) {
        Node* newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Inserted " << value << " after " << key << ".\n";
    } else {
        cout << "Key " << key << " not found.\n";
    }
}

void deleteAtBeginning() {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    cout << "Deleted " << temp->data << " from beginning.\n";
    delete temp;
}

void deleteAtEnd() {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    if (!head->next) {
        cout << "Deleted " << head->data << " from end.\n";
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next) temp = temp->next;
    cout << "Deleted " << temp->next->data << " from end.\n";
    delete temp->next;
    temp->next = nullptr;
    }

    void deleteNode(int key) {
        if (!head) {
        cout << "List is empty.\n";
        return;
        }
        if (head->data == key) {
        deleteAtBeginning();
        return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data != key) {
            temp = temp->next;
        }
        if (temp->next) {
            Node* del = temp->next;
            temp->next = del->next;
            cout << "Deleted node with value " << key << ".\n";
            delete del;
        } else {
        cout << "Node with value " << key << " not found.\n";
        }
    }

    void searchNode(int key) {
        Node* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == key) {
            cout << "Node " << key << " found at position " << pos << ".\n";
            return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node " << key << " not found in the list.\n";
    }

    void displayList() {
        if (!head) {
        cout << "List is empty.\n";
        return;
        }
        Node* temp = head;
        cout << "List: ";
        while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
        }
        cout << "NULL\n";
    }

};




Node* RemoveOccurences(Node*& head, int key){
    Node* curr = head;
    Node* prev = NULL;
    int count = 0;
    while(curr != NULL){
        if(curr->data == key){
            Node*temp = curr;
            if(prev)prev->next = curr->next;
            else head = curr->next;

            curr = curr->next;
            count++;
            delete temp;
        }
        else{
            prev = curr;
            curr = curr->next;
        }
    }

    cout << count << " occurences of " << key << " have been removed" << endl;
    return head;
}

int main(){
    LinkedList ll;
    ll.insertAtEnd(1);
    ll.insertAtEnd(2);
    ll.insertAtEnd(3);
    ll.insertAtEnd(2);
    ll.insertAtEnd(2);
    ll.insertAtEnd(4);
    ll.insertAtEnd(5);
    ll.insertAtEnd(2);
    ll.insertAtEnd(2);
    ll.displayList();
    Node* head = ll.head;
    ll.head = RemoveOccurences(head, 2);
    ll.displayList();
    return 0;
}
