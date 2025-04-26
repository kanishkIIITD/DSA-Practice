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
    int findHeight(TreeNode* root){
        if(root == NULL) {
            return 0;
        };

        int leftHeight = 1 + findHeight(root->left);
        int rightHeight = 1 + findHeight(root->right);
        return max(leftHeight, rightHeight);
    }
    int maxDepth(TreeNode* root) {
        return findHeight(root);
    }
};