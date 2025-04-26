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
    int findHeight(TreeNode* root, int& height){
        if(root == NULL) return NULL;
        int leftHeight = findHeight(root -> left, height);
        int rightHeight = findHeight(root -> right, height);
        height = max(height, leftHeight + rightHeight);
        return 1 + max(leftHeight, rightHeight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int height = 0;
        findHeight(root, height);
        return height;
    }
};