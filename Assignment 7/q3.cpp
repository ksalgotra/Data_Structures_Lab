#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v) {
        data = v;
        left = right = NULL;
    }
};


class BST {
public:
    Node* root;

    BST() : root(NULL) {}

    Node* insert(Node* node, int val) {
        if (node == NULL)
            return new Node(val);

        if (val < node->data)
            node->left = insert(node->left, val);
        else if (val > node->data)
            node->right = insert(node->right, val);

        return node; 
    }

    void insert(int val) {
        root = insert(root, val);
    }

    Node* findMin(Node* node) {
        while (node && node->left)
            node = node->left;
        return node;
    }

    
    Node* deleteNode(Node* node, int val) {
        if (node == NULL)
            return node;

        if (val < node->data)
            node->left = deleteNode(node->left, val);
        else if (val > node->data)
            node->right = deleteNode(node->right, val);
        else {
         
            if (node->left == NULL && node->right == NULL) {
                delete node;
                return NULL;
            } 
            else if (node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp;
            } 
            else if (node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp;
            } 
            else {
                // Node with two children
                Node* temp = findMin(node->right);
                node->data = temp->data;
                node->right = deleteNode(node->right, temp->data);
            }
        }
        return node;
    }

    void deleteValue(int val) {
        root = deleteNode(root, val);
    }

    int maxDepth(Node* node) {
        if (node == NULL)
            return 0;
        return 1 + max(maxDepth(node->left), maxDepth(node->right));
    }

    int minDepth(Node* node) {
        if (node == NULL)
            return 0;
        if (!node->left && !node->right)
            return 1;
        if (!node->left)
            return 1 + minDepth(node->right);
        if (!node->right)
            return 1 + minDepth(node->left);
        return 1 + min(minDepth(node->left), minDepth(node->right));
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

    int elements[] = {15, 10, 20, 8, 12, 17, 25};
    for (int val : elements)
        tree.insert(val);

    cout << "BST (Inorder Traversal): ";
    tree.inorder(tree.root);
    cout << endl;

    
    cout << "\nDeleting node 20...\n";
    tree.deleteValue(20);

    cout << "BST after deletion (Inorder): ";
    tree.inorder(tree.root);
    cout << endl;

    cout << "\nMaximum Depth of BST: " << tree.maxDepth(tree.root) << endl;
    cout << "Minimum Depth of BST: " << tree.minDepth(tree.root) << endl;

    return 0;
}
