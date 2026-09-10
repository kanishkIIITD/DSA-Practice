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
    pair<int, int> solve(TreeNode* root, int& count){
        if(!root)
            return {0, 0};
        auto left = solve(root->left, count);
        auto right = solve(root->right, count);
        int sum = left.first + right.first + root->val;
        int n = left.second + right.second + 1;
        if(sum / n == root->val)
            count++;
        return {sum, n};
    }
    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        solve(root, count);
        return count;
    }
};