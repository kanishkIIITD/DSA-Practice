/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void createMap(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& mp){
        if(!root)
            return;
        if(root->left) mp[root->left] = root;
        if(root->right) mp[root->right] = root;
        createMap(root->left, mp);
        createMap(root->right, mp);
    }
    void traverse(TreeNode* target, unordered_map<TreeNode*, TreeNode*>& mp, int k, vector<int>& ans, unordered_map<TreeNode*, int>& vis){
        if(!target)
            return;
        if(k == 0){
            ans.push_back(target->val);
        }
        vis[target] = 1;
        if(!vis[target->left])
            traverse(target->left, mp, k-1, ans, vis);
        if(!vis[target->right])
            traverse(target->right, mp, k-1, ans, vis);
        if(!vis[mp[target]])
            traverse(mp[target], mp, k-1, ans, vis);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> mp; //node -> parent
        createMap(root, mp);
        vector<int> ans;
        unordered_map<TreeNode*, int> vis;
        traverse(target, mp, k, ans, vis);
        return ans;
    }
};