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
    void createMap(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& mp){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                mp[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                mp[node->right] = node;
                q.push(node->right);
            }
        }
    }
    TreeNode* getNode(TreeNode* root, int start){
        if(!root)
            return NULL;
        
        if(root->val == start)
            return root;
        
        TreeNode* left = getNode(root->left, start);
        TreeNode* right = getNode(root->right, start);

        if(!left && !right)
            return NULL;
        else if(!left)
            return right;
        else
            return left;

    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> mp;
        createMap(root, mp);
        int ans = 0;
        TreeNode* startNode = getNode(root, start);
        queue<TreeNode*> q;
        unordered_map<TreeNode*, bool> vis;
        q.push(startNode);
        vis[startNode] = true;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left && !vis[curr->left]){
                    q.push(curr->left);
                    vis[curr->left] = true;
                }
                if(curr->right && !vis[curr->right]){
                    q.push(curr->right);
                    vis[curr->right] = true;
                }
                if(mp[curr] && !vis[mp[curr]]){
                    q.push(mp[curr]);
                    vis[mp[curr]] = true;
                }
            }
            ans++;
        }
        return ans-1;
    }
};