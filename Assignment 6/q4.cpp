#include <iostream>
using namespace std;

class Node {
public:
    char data;        
    Node* next;
    Node* prev;
    Node(char val) {
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

    void insertAtEnd(char val) {  
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

    
    bool isPalindrome() {
        if (!head) return true; 

        Node* l = head;
        Node* r = head;

        while (r->next != NULL) {
            r = r->next;
        }

        // Compare from both ends
        while (l != r && r->next != l) {
            if (l->data != r->data)
                return false;
            l = l->next;
            r = r->prev;
        }
        return true;
    }
};

int main() {
    DoublyLinkedList dll;
    int n;
    char ch;

    cout << "Enter number of characters: ";
    cin >> n;

    cout << "Enter characters one by one:\n";
    for (int i = 0; i < n; i++) {
        cin >> ch;
        dll.insertAtEnd(ch);
    }

    cout << "\nThe Doubly Linked List is: ";
    dll.displayList();

    if (dll.isPalindrome())
        cout << "Output: It is a palindrome\n";
    else
        cout << "Output: It is not a palindrome\n";

    return 0;
}
