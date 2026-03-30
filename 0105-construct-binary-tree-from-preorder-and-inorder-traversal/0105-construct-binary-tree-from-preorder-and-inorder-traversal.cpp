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
    TreeNode* solve(vector<int>& preorder, int preLow, int preHigh, vector<int>& inorder, int inLow, int inHigh){
        if(inLow > inHigh && preLow > preHigh)
            return NULL;
        TreeNode* root = new TreeNode(preorder[preLow]);

        int index = inLow;
        while(index <= inHigh){
            if(inorder[index] == preorder[preLow])
                break;
            index++;
        }

        root->left = solve(preorder, preLow+1, preLow+index-inLow, inorder, inLow, index-1);
        root->right = solve(preorder, preLow+index-inLow+1, preHigh, inorder, index+1, inHigh);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return solve(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};