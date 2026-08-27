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
    int solve(TreeNode* node , int& res){
        if (!node) return 0;

        int lft = solve(node->left ,res);
        int right = solve(node->right ,res);

        res = max(res , lft +right);
        
        return 1 + max(lft , right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        solve(root , res);
        return res;
    }
};
