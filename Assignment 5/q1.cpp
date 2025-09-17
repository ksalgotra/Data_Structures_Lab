#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

Node* head = NULL;

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



int main() {
    int choice, value, key;
    char cont;  

    do {
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert before a node\n";
        cout << "4. Insert after a node\n";
        cout << "5. Delete at beginning\n";
        cout << "6. Delete at end\n";
        cout << "7. Delete specific node\n";
        cout << "8. Search a node\n";
        cout << "9. Display list\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertAtBeginning(value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                insertAtEnd(value);
                break;

            case 3:
                cout << "Enter key(before which to insert): ";
                cin >> key;
                cout << "Enter new value: ";
                cin >> value;
                insertBefore(key, value);
                break;

            case 4:
                cout << "Enter key(after which to insert): ";
                cin >> key;
                cout << "Enter new value: ";
                cin >> value;
                insertAfter(key, value);
                break;

            case 5:
                deleteAtBeginning();
                break;

            case 6:
                deleteAtEnd();
                break;

            case 7:
                cout << "Enter node value to delete: ";
                cin >> key;
                deleteNode(key);
                break;

            case 8:
                cout << "Enter value to search: ";
                cin >> key;
                searchNode(key);
                break;

            case 9:
                displayList();
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
