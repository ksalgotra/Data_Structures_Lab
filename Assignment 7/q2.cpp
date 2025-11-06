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


class BST {
public:
    Node* root;

    BST() : root(NULL) {}

    //Insert an element 
    void insert(int val) {
        Node* newNode = new Node(val);
        if (!root) {
            root = newNode;
            return;
        }

        Node* current = root;
        Node* parent = nullptr;

        while (current) {
            parent = current;
            if (val < current->data)
                current = current->left;
            else if (val > current->data)
                current = current->right;
            else
                return; 
        }

        if (val < parent->data)
            parent->left = newNode;
        else
            parent->right = newNode;
    }

    Node* searchRecursive(Node* node, int key) {
        if (node == nullptr || node->data == key)
            return node;
        if (key < node->data)
            return searchRecursive(node->left, key);
        else
            return searchRecursive(node->right, key);
    }

    Node* searchIterative(Node* node, int key) {
        while (node) {
            if (key == node->data)
                return node;
            else if (key < node->data)
                node = node->left;
            else
                node = node->right;
        }
        return nullptr;
    }


    Node* findMin(Node* node) {
        if (!node) return nullptr;
        while (node->left)
            node = node->left;
        return node;
    }

   
    Node* findMax(Node* node) {
        if (!node) return nullptr;
        while (node->right)
            node = node->right;
        return node;
    }

   
    Node* inorderSuccessor(Node* root, int key) {
        Node* current = root;
        Node* successor = nullptr;

        while (current) {
            if (key < current->data) {
                successor = current;
                current = current->left;
            } else if (key > current->data)
                current = current->right;
            else
                break;
        }

        if (!current) return nullptr;
        if (current->right)
            return findMin(current->right);
        return successor;
    }

   
    Node* inorderPredecessor(Node* root, int key) {
        Node* current = root;
        Node* predecessor = nullptr;

        while (current) {
            if (key > current->data) {
                predecessor = current;
                current = current->right;
            } else if (key < current->data)
                current = current->left;
            else
                break;
        }

        if (!current) return nullptr;
        if (current->left)
            return findMax(current->left);
        return predecessor;
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
};


int main() {
    BST tree;

    int elements[] = {20, 8, 22, 4, 12, 10, 14};
    for (int val : elements)
        tree.insert(val);

    cout << "BST (Inorder Traversal): ";
    tree.inorder(tree.root);
    cout << endl;

    cout << "Recursive Search for 10: "
         << (tree.searchRecursive(tree.root, 10) ? "Found" : "Not Found") << endl;
    cout << "Iterative Search for 15: "
         << (tree.searchIterative(tree.root, 15) ? "Found" : "Not Found") << endl;

    cout << "\nMinimum element: " << tree.findMin(tree.root)->data << endl;
    cout << "Maximum element: " << tree.findMax(tree.root)->data << endl;

    int target = 12;
    Node* succ = tree.inorderSuccessor(tree.root, target);
    Node* pred = tree.inorderPredecessor(tree.root, target);

    cout << "\n(c) Inorder Successor of " << target << ": "
         << (succ ? succ->data : -1) << endl;

    cout << "(c) Inorder Predecessor of " << target << ": "
         << (pred ? pred->data : -1) << endl;

    return 0;
}
