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
    bool solve(TreeNode* root, long mini, long maxi){
        if(!root) return true;
        if(mini >= root->val || root->val >= maxi)
            return false;
        return solve(root->left, mini, root->val) && solve(root->right, root->val, maxi);
    }
    bool isValidBST(TreeNode* root) {
        long mini = LONG_MIN, maxi = LONG_MAX;
        return solve(root, mini, maxi);
    }
};