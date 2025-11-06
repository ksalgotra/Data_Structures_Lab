#include <iostream>
#include <climits>
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

class BinaryTree {
public:
    Node* root;

    BinaryTree() : root(NULL) {}

    
    Node* insert(Node* node, int val) {
        if (node == NULL)
            return new Node(val);

        if (val < node->data)
            node->left = insert(node->left, val);
        else
            node->right = insert(node->right, val);

        return node;
    }

    void insert(int val) {
        root = insert(root, val);
    }

    // Check if tree is BST
    bool isBSTUtil(Node* node, int minVal, int maxVal) {
        if (!node)
            return true;

        if (node->data <= minVal || node->data >= maxVal)
            return false;

        return isBSTUtil(node->left, minVal, node->data) &&
               isBSTUtil(node->right, node->data, maxVal);
    }

    bool isBST(Node* root) {
        return isBSTUtil(root, INT_MIN, INT_MAX);
    }

    // Inorder Traversal
    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
};

int main() {
    BinaryTree tree;

    // Constructing a valid BST
    int elements[] = {15, 10, 20, 8, 12, 17, 25};
    for (int val : elements)
        tree.insert(val);

    cout << "Binary Tree (Inorder Traversal): ";
    tree.inorder(tree.root);
    cout << endl;

    if (tree.isBST(tree.root))
        cout << "\nThe given tree IS a Binary Search Tree.\n";
    else
        cout << "\nThe given tree is NOT a Binary Search Tree.\n";

    // Example of invalid tree
    Node* invalidRoot = new Node(10);
    invalidRoot->left = new Node(15); // violates BST property
    invalidRoot->right = new Node(5);

    cout << "\nInvalid Tree (Inorder Traversal): ";
    tree.inorder(invalidRoot);
    cout << endl;

    if (tree.isBST(invalidRoot))
        cout << "\nThe given tree IS a Binary Search Tree.\n";
    else
        cout << "\nThe given tree is NOT a Binary Search Tree.\n";

    return 0;
}
