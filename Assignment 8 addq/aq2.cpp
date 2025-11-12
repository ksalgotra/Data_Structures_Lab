/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> Builder(int st, int end){
        if(st > end)return {NULL};

        vector<TreeNode*> trees;
        for(int i = st; i <= end; i++){
            vector<TreeNode*> leftSubTrees = Builder(st, i - 1);
            vector<TreeNode*> rightSubTrees = Builder(i + 1, end);

            for(auto& l : leftSubTrees){
                for(auto& r : rightSubTrees){
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    trees.push_back(root);
                }
            }

        }
        return trees;
    }
    vector<TreeNode*> generateTrees(int n) {
        return Builder(1, n);
    }
};
