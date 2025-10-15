#include <iostream>
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

    void insertAtFirst(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            head->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            head->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }

    void insertAfter(int key, int val) {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        do {
            if (temp->data == key) {
                Node* newNode = new Node(val);
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Key not found\n";
    }

    void insertBefore(int key, int val) {
        if (!head) {
            cout << "List is empty\n";
            return;
        }

        Node* newNode = new Node(val);
        Node* temp = head;
        Node* prev = NULL;

        do {
            if (temp->data == key) {
                if (prev == NULL) { // before head
                    insertAtFirst(val);
                    delete newNode; 
                    return;
                }
                prev->next = newNode;
                newNode->next = temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != head);

        cout << "Key not found\n";
        delete newNode;
    }

    void DeleteNode(int key) {
        if (!head) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        Node* prev = NULL;

        
        if (head->next == head && head->data == key) {
            delete head;
            head = NULL;
            return;
        }

        
        if (head->data == key) {
            while (temp->next != head)
                temp = temp->next;
            temp->next = head->next;
            Node* del = head;
            head = head->next;
            delete del;
            return;
        }

        do {
            prev = temp;
            temp = temp->next;
            if (temp->data == key) {
                prev->next = temp->next;
                delete temp;
                return;
            }
        } while (temp != head);

        cout << "Key not found\n";
    }

    bool SearchNode(int key) {
        if (!head) {
            cout << "Empty list\n";
            return false;
        }
        Node* temp = head;
        do {
            if (temp->data == key) {
                cout << "Key " << key << " found\n";
                return true;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Key not found\n";
        return false;
    }

    void displayList() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to head)\n";
    }
};

int main() {
    CircularLinkedList cll;
    int choice, value, key;
    char cont;

    do {
        cout << "\n*** Circular Linked List Menu ***\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert before a node\n";
        cout << "4. Insert after a node\n";
        cout << "5. Delete a node\n";
        cout << "6. Search a node\n";
        cout << "7. Display list\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            cll.insertAtFirst(value);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> value;
            cll.insertAtEnd(value);
            break;
        case 3:
            cout << "Enter key (before which to insert): ";
            cin >> key;
            cout << "Enter new value: ";
            cin >> value;
            cll.insertBefore(key, value);
            break;
        case 4:
            cout << "Enter key (after which to insert): ";
            cin >> key;
            cout << "Enter new value: ";
            cin >> value;
            cll.insertAfter(key, value);
            break;
        case 5:
            cout << "Enter value to delete: ";
            cin >> key;
            cll.DeleteNode(key);
            break;
        case 6:
            cout << "Enter value to search: ";
            cin >> key;
            cll.SearchNode(key);
            break;
        case 7:
            cll.displayList();
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }

        cout << "Continue? (y/n): ";
        cin >> cont;
    } while (cont == 'y' || cont == 'Y');
    return 0;
}
