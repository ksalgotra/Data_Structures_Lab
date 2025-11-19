#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left, *right;
    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};


struct DLLNode {
    int data;
    DLLNode *prev, *next;
    DLLNode(int val) : data(val), prev(NULL), next(NULL) {}
};

// insert at end of DLL
void insertAtEnd(DLLNode* &head, DLLNode* &tail, DLLNode* curr) {
    if (!head) {
        head = tail = curr;
        return;
    }
    tail->next = curr;
    curr->prev = tail;
    tail = curr;
}


void inorderToDLL(TreeNode* root, DLLNode* &head, DLLNode* &tail) {
    if (!root) return;
    inorderToDLL(root->left, head, tail);
    insertAtEnd(head, tail, new DLLNode(root->data));
    inorderToDLL(root->right, head, tail);
}


DLLNode* mergeDLL(DLLNode* a, DLLNode* b) {
    if (!a) return b;
    if (!b) return a;

    DLLNode* head = NULL;
    DLLNode* tail = NULL;

    while (a && b) {
        if (a->data < b->data) {
            insertAtEnd(head, tail, new DLLNode(a->data));
            a = a->next;
        } else {
            insertAtEnd(head, tail, new DLLNode(b->data));
            b = b->next;
        }
    }

    while (a) { insertAtEnd(head, tail, new DLLNode(a->data)); a = a->next; }
    while (b) { insertAtEnd(head, tail, new DLLNode(b->data)); b = b->next; }

    return head;
}

void printDLL(DLLNode* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // First BST
    TreeNode* a = new TreeNode(20);
    a->left = new TreeNode(10);
    a->right = new TreeNode(30);
    a->right->left = new TreeNode(25);
    a->right->right = new TreeNode(100);

    // Second BST
    TreeNode* b = new TreeNode(50);
    b->left = new TreeNode(5);
    b->right = new TreeNode(70);


    DLLNode *head1 = NULL, *tail1 = NULL;
    inorderToDLL(a, head1, tail1);

    DLLNode *head2 = NULL, *tail2 = NULL;
    inorderToDLL(b, head2, tail2);

    DLLNode* mergedHead = mergeDLL(head1, head2);

 
    printDLL(mergedHead);

    return 0;
}
