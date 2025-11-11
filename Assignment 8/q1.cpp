#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v){
        data = v;
        left = NULL;
        right = NULL;
    }
};

void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}


Node* sampleTree() {
    Node* r = new Node(1);
    r->left = new Node(2);
    r->right = new Node(3);
    r->left->left = new Node(4);
    r->left->right = new Node(5);
    r->right->left = new Node(6);
    return r;
}

int main() {
    Node* root = sampleTree();
    cout << "Pre-order: ";
    preorder(root);
    cout << "\nIn-order:  ";
    inorder(root);
    cout << "\nPost-order:";
    postorder(root);
    cout << "\n";

    return 0;
}
