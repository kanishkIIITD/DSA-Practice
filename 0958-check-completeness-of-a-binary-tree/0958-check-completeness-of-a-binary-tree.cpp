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
    bool isCompleteTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        int count = 1;
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int value = q.front().second;
            q.pop();
            if(value > count)
                return false;
            if(node->left)
                q.push({node->left, 2*value});
            if(node->right)
                q.push({node->right, 2*value + 1});
            count++;
        }
        return true;
    }
};