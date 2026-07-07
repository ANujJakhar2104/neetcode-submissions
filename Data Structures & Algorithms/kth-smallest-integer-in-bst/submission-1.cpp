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
    int ans = 0;
    void solve(TreeNode* node , int k , int& cnt){
        if (!node) return ;

        if (node->left == nullptr) {
            cnt += 1;
            if (cnt == k) ans = node->val;
            solve(node->right , k ,cnt);
            return;
        }

        solve(node->left , k , cnt);
        if (cnt != 0) cnt += 1;
        if (cnt == k){
            ans = node->val;
            return;
        }
        solve(node->right , k , cnt);
    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt =0;
        solve(root , k , cnt);
        return ans;
    }
};
