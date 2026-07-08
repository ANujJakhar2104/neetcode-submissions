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
    unordered_map<int,int> mp;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }

        return solve(0,preorder.size()-1,0,inorder.size()-1,preorder,inorder);
    }

    TreeNode* solve(int presrt , int preend , int insrt , int inend , 
        vector<int>& preorder, vector<int>& inorder){
            if(presrt > preend || insrt > inend) return nullptr;

            TreeNode* node = new TreeNode(preorder[presrt]);
            int in_node = mp[node->val];
            int num_left = in_node - insrt;

            node->left = solve(presrt+1 , presrt+num_left , insrt , in_node-1,preorder,inorder);
            node->right = solve(presrt+num_left+1 , preend , in_node+1 , inend,preorder,inorder);

            return node;
        }
};
