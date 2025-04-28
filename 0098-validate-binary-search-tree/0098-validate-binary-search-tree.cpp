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
    bool solve(TreeNode* root, long leftMax, long rightMax){
        if(!root)
            return true;
        if(root->val >= rightMax || root->val <= leftMax)
            return false;
        return solve(root->left, leftMax, root->val) && solve(root->right, root->val, rightMax);
    }
    bool isValidBST(TreeNode* root) {
        long leftMax = LONG_MIN;
        long rightMax = LONG_MAX;
        return solve(root, leftMax, rightMax);
    }
};