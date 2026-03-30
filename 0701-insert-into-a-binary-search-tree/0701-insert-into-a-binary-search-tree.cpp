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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = new TreeNode(val);
        if(!root)
            return node;
        TreeNode* curr = root;
        TreeNode* prev = NULL;
        bool flag = 0;
        while(curr){
            prev = curr;
            if(curr->val < val){
                curr = curr->right;
                flag = 0;
            }
            else{
                curr = curr->left;
                flag = 1;
            }
        }
        flag == 0 ? prev->right = node : prev->left = node;
        return root;
    }
};