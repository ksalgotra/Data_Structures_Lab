#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int& postIdx, int l, int r, unordered_map<int,int>& m){
        if(l > r) return NULL;

        TreeNode* root = new TreeNode(postorder[postIdx]);
        int inIdx = m[postorder[postIdx]];
        postIdx--;

        root->right = helper(inorder, postorder, postIdx, inIdx + 1, r, m);
        root->left = helper(inorder, postorder, postIdx, l, inIdx - 1, m);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postIdx = postorder.size() - 1;
        unordered_map<int,int> m;
        for(int i = 0 ; i < inorder.size() ; i++){
            m[inorder[i]] = i;
        }
        return helper(inorder, postorder, postIdx, 0, inorder.size() - 1, m);
    }
};
void printLevelOrder(TreeNode* root) {
    if (!root) {
        cout << "Empty Tree";
        return;
    }
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* front = q.front();
        q.pop();
        cout << front->val << " ";
        if (front->left) q.push(front->left);
        if (front->right) q.push(front->right);
    }
}

int main() {
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    Solution s;
    TreeNode* root = s.buildTree(inorder, postorder);

    cout << "Level Order of Constructed Tree: ";
    printLevelOrder(root);  // Output: 3 9 20 15 7
    cout << endl;

    return 0;
}
