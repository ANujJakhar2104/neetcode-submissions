class Solution {
public:
    bool isValidBST(TreeNode* node) {
        return solve(node, LONG_MIN, LONG_MAX);
    }

    bool solve(TreeNode* node, long minVal, long maxVal) {
        if (!node) return true;

        int lft = 0;
        if (node->left) lft = node->left->val;
        int right = 0;
        if (node->right) right = node->right->val;

        if (node->val <= minVal || node->val >= maxVal) return false;

        return solve(node->left, minVal, node->val) &&
               solve(node->right, node->val, maxVal);
    }
};