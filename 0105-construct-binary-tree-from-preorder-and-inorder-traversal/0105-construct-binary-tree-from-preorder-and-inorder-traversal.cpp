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
    TreeNode* solve(vector<int>& preorder, int preS, int preE, vector<int>&inorder, int inS, int inE){
        if(preS > preE)
            return NULL;
        TreeNode* root = new TreeNode(preorder[preS]);
        int rootIndex = inS;
        while(inorder[rootIndex] != preorder[preS]){
            rootIndex++;
        }
        int leftLen = rootIndex - inS;

        root->left = solve(preorder, preS + 1, preS + leftLen, inorder, inS, rootIndex - 1);

        root->right = solve(preorder, preS + leftLen + 1, preE, inorder, rootIndex + 1, inE);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preS = 0, inS = 0;
        int preE = preorder.size()-1, inE = inorder.size()-1;
        TreeNode* root = solve(preorder, preS, preE, inorder, inS, inE);
        return root;
    }
};