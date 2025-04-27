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
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        
        int leftHeight = 0; //Height from root till there is left node availabe
        int rightHeight = 0; //Height from root till there is right node available
        
        TreeNode* leftNode = root;
        while(leftNode){
            leftHeight++;
            leftNode = leftNode->left;
        }

        TreeNode* rightNode = root;
        while(rightNode){
            rightHeight++;
            rightNode = rightNode->right;
        }

        if(leftHeight == rightHeight)
            return pow(2, leftHeight) - 1;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};