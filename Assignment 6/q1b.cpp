#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
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
};

int main() {
    DoublyLinkedList dll;
    int choice, value, key;
    char cont;

    do {
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert before a node\n";
        cout << "4. Insert after a node\n";
        cout << "5. Delete specific node\n";
        cout << "6. Search a node\n";
        cout << "7. Display list\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            dll.insertAtFirst(value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            dll.insertAtEnd(value);
            break;

        case 3:
            cout << "Enter key(before which to insert): ";
            cin >> key;
            cout << "Enter new value: ";
            cin >> value;
            dll.insertBefore(key, value);
            break;

        case 4:
            cout << "Enter key(after which to insert): ";
            cin >> key;
            cout << "Enter new value: ";
            cin >> value;
            dll.insertAfter(key, value);
            break;

        case 5:
            cout << "Enter node value to delete: ";
            cin >> key;
            dll.DeleteNode(key);
            break;

        case 6:
            cout << "Enter value to search: ";
            cin >> key;
            dll.SearchNode(key);
            break;

        case 7:
            cout << "The Doubly Linked List is : "; 
            dll.displayList();
            break;

        case 0:
            cout << "Program terminated.\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

        cout << "\nDo you want to continue? Enter y/Y to continue : ";
        cin >> cont;

    } while (cont == 'y' || cont == 'Y');

    cout << "Program terminated.\n";
    return 0;
}
