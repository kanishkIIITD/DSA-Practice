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
        TreeNode* ans = new TreeNode(val);
        if(!root)
            return ans;
        TreeNode* curr = root;
        while(curr){
            if(curr->val > val){
                if(!curr->left){
                    curr->left = ans;
                    return root;
                }
                curr = curr->left;
            }   
            else{
                if(!curr->right){
                    curr->right = ans;
                    return root;
                }
                curr = curr->right;
            }
        }
        return root;
    }
};