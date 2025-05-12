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
    void createMap(TreeNode* root, unordered_map<TreeNode*, TreeNode*>&mp){
        if(!root) return;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
                mp[node->left] = node;
            }
            if(node->right){
                q.push(node->right);
                mp[node->right] = node;
            }    
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> mp;
        createMap(root, mp);
        vector<int> ans;
        queue<TreeNode*>q;
        unordered_map<TreeNode*, bool> vis;
        q.push(target);
        vis[target] = true;
        int dist = 0;
        while(!q.empty()){
            if(dist++ == k)
                break;
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left && !vis[node->left]){
                    q.push(node->left);
                    vis[node->left] = true;
                }
                if(node->right && !vis[node->right]){
                    q.push(node->right);
                    vis[node->right] = true;
                }
                if(mp[node] && !vis[mp[node]]){
                    q.push(mp[node]);
                    vis[mp[node]] = true;
                }
            }
        }
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            ans.push_back(node->val);
        }
        return ans;
    }
};