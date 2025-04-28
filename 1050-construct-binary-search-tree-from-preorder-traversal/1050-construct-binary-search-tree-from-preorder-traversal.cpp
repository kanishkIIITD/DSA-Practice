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
    TreeNode* solve(vector<int>&preorder, int start, int end){
        if(start > end)
            return NULL;
        TreeNode* root = new TreeNode(preorder[start]);
        if(start == end)
            return root;
        int idx = start+1;
        while(idx <= end && preorder[idx] < root->val) {
            idx++;
        }
        root->left = solve(preorder, start+1, idx-1);
        root->right = solve(preorder, idx, end);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int start = 0;
        int end = preorder.size()-1;
        return solve(preorder, start, end);
    }
};