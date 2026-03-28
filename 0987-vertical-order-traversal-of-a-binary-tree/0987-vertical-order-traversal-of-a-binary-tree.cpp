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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> q;
        vector<vector<int>> ans;
        if(!root)
            return ans;
        q.push({root, {0, 0}});
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            TreeNode* currNode = front.first;
            int x = front.second.first;
            int y = front.second.second;
            nodes[y][x].insert(currNode->val);
            if(currNode->left)
                q.push({currNode->left, {x+1, y-1}});
            if(currNode->right)
                q.push({currNode->right, {x+1, y+1}});
        }
        for(auto node: nodes){
            vector<int> col;
            for(auto p: node.second){
                col.insert(col.end(), p.second.begin(), p.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};