# include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

class BinaryTree{
public:
    Node* root;

    BinaryTree(){
        root = NULL;
    }

    Node* insert(Node* node, int val) {
        if (node == NULL)
            return new Node(val);

        if (val < node->data)
            node->left = insert(node->left, val);
        else if (val > node->data)
            node->right = insert(node->right, val);

        return node; 
    }

    int countLeftLeafNodes(){
        Node* parent = NULL;
        Node* curr = root;

        return helper(root, NULL);

    }

    int helper(Node* curr, Node* parent){
        if(!curr)return 0;
        return helper(curr->left, curr) + helper(curr->right, curr) + ((curr->left == NULL && curr->right == NULL && parent->left == curr)? 1 : 0);
    }

};

int main(){
    BinaryTree BT;

    BT.root = BT.insert(BT.root, 3);
    BT.root = BT.insert(BT.root, 2);
    BT.root = BT.insert(BT.root, 20);
    BT.root = BT.insert(BT.root, 15);
    BT.root = BT.insert(BT.root, 21);

    cout << "Left Leaf nodes are :" << BT.countLeftLeafNodes() << endl;

}
