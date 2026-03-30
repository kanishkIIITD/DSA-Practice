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
    TreeNode* solve(vector<int>& postorder, int postLow, int postHigh, vector<int>& inorder, int inLow, int inHigh){
        if(inLow > inHigh || postLow > postHigh)
            return NULL;
        TreeNode* root = new TreeNode(postorder[postHigh]);

        int index = inLow;
        while(index <= inHigh){
            if(inorder[index] == postorder[postHigh])
                break;
            index++;
        }

        root->left = solve(postorder, postLow, postLow+index-inLow-1, inorder, inLow, index-1);
        root->right = solve(postorder, postLow+index-inLow, postHigh-1, inorder, index+1, inHigh);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return solve(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1);
    }
};