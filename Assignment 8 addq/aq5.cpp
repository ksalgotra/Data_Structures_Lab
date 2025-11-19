#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int search(vector<int>& inorder, int l, int r, int val) {
        for (int i = l; i <= r; i++) {
            if (inorder[i] == val)
                return i;
        }
        return -1;
    }

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int& preIdx, int l, int r) {
        if (l > r) return nullptr;

        TreeNode* root = new TreeNode(preorder[preIdx]);
        int inIdx = search(inorder, l, r, preorder[preIdx]);
        preIdx++;

        root->left = helper(preorder, inorder, preIdx, l, inIdx - 1);
        root->right = helper(preorder, inorder, preIdx, inIdx + 1, r);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx = 0;
        return helper(preorder, inorder, preIdx, 0, inorder.size() - 1);
    }
};

int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Solution s;
    TreeNode* root = s.buildTree(preorder, inorder);

    cout << "Tree built successfully." << endl;
    return 0;
}
