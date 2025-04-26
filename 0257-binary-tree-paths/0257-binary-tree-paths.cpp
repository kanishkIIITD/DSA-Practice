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
    void solve(TreeNode* root, string&s, vector<string>&ans){
        if(!root){
            return;
        }
        int originalLen = s.size();
        if(!s.empty())
            s += "->"; 
        s += to_string(root->val);
        if(!root->left && !root->right){
            ans.push_back(s);
        }
        solve(root->left, s, ans);
        solve(root->right, s, ans);
        s.resize(originalLen);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string s = "";
        vector<string> ans;
        solve(root, s, ans);
        return ans;
    }
};