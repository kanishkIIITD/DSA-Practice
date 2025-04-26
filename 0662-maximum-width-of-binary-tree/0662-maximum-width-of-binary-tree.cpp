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
    int widthOfBinaryTree(TreeNode* root) {
        unsigned long long width = 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        if(!root) return 0;
        q.push({root, 0});
        while(!q.empty()){
            int size = q.size();
            unsigned long long mini = q.front().second;
            unsigned long long first, second;
            for(int i = 0; i < size; i++){
                unsigned long long curr = q.front().second - mini;
                TreeNode* node = q.front().first;
                q.pop();
                if(i == 0)
                    first = curr;
                if(i == size-1)
                    second = curr;
                if(node->left)
                    q.push({node->left, curr*2+1});
                if(node->right)
                    q.push({node->right, curr*2+2});
            }
            width = max(width, second-first+1);
        }
        return width;
    }
};