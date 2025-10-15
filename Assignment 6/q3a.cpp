 include<iostream>
using namespace std;


class Node{
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() {
        head = NULL;
    }

    void insertAtFirst(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    void insertAfter(int key, int val) {
        if (!head) {
            cout << "INVALID REQUEST" << endl;
            return;
        }

        Node* temp = head;
        while (temp && temp->data != key) {
            temp = temp->next;
        }
        if (!temp) {
            cout << "KEY NOT FOUND" << endl;
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next)               
            temp->next->prev = newNode; 

        temp->next = newNode;        
    }

    void insertBefore(int key, int val) {
        if (!head) {
            cout << "INVALID REQUEST" << endl;
            return;
        }

        Node* temp = head;
        while (temp && temp->data != key) {
            temp = temp->next;
        }

        if (!temp) {
            cout << "KEY NOT FOUND" << endl;
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp;
        newNode->prev = temp->prev;

        if (temp->prev)
            temp->prev->next = newNode;
        else
            head = newNode; // (for inserting before head)

        temp->prev = newNode; 
    }

    void DeleteNode(int key) {
        if (!head) {
            cout << "Empty DLL" << endl;
            return;
        }

        Node* temp = head;
        while (temp && temp->data != key) {
            temp = temp->next;
        }

        if (!temp) {
            cout << "KEY NOT FOUND" << endl;
            return;
        }

        if (temp == head)               
            head = head->next;         

        if (temp->next)
            temp->next->prev = temp->prev;

        if (temp->prev)
            temp->prev->next = temp->next;

        delete temp;
    }

    bool SearchNode(int key) {
        if (!head) {
            cout << "Empty DLL" << endl;
            return false;
        }
        Node* temp = head;
        while (temp && temp->data != key) {
            temp = temp->next;
        }
        if (!temp) {
            cout << "KEY NOT FOUND" << endl; 
            return false;
        }
        cout << "KEY FOUND" << endl; 
        return true;
    }

    void displayList() {
        if (!head) {
            cout << "Empty DLL" << endl;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            cout << temp->data << "<->";
            temp = temp->next;
        }
        cout << temp->data << endl;
    }

    int getSize() {
        int size = 0;
        Node* temp = head;
        while (temp) {
            size++;
            temp = temp->next;
        }
        return size;
    }
};


int main(){
    DoublyLinkedList dll;
    dll.insertAtEnd(1);
    dll.insertAtEnd(2);
    dll.insertAtEnd(3);

    cout << dll.getSize() << endl;
}
