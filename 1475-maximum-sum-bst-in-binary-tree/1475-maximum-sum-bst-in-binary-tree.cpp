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
    int maxSum = 0;
public:
    struct Info{
        bool isBST;
        int minval;
        int maxval;
        int sum;
    };
    int maxSumBST(TreeNode* root) {
        postorder(root);
        return maxSum;
    }
    Info postorder(TreeNode* root){
        if(!root){
            return {true , INT_MAX, INT_MIN, 0};
        }
        Info left = postorder(root->left);
        Info right = postorder(root->right);
        if(left.isBST && right.isBST && root->val > left.maxval && root->val < right.minval){
            int curSum = (root->val + left.sum + right.sum);
            maxSum = max(curSum , maxSum);
            return {true , min(root->val , left.minval) , max(root->val,right.maxval) ,curSum};
        }
        return {false , 0 , 0 , 0};
    }

};
// class Solution {
//     int maxSum = 0;

// public:
//     int maxSumBST(TreeNode* root) {
//         dfs(root);
//         return maxSum;
//     }

//     // Helper to do a DFS on each subtree
//     void dfs(TreeNode* node) {
//         if (!node) return;

//         if (isBST(node)) {
//             int sum = sumTree(node);
//             maxSum = max(maxSum, sum);
//         }

//         dfs(node->left);
//         dfs(node->right);
//     }

//     // Check if a tree is a valid BST using inorder traversal
//     bool isBST(TreeNode* root) {
//         vector<int> vals;
//         inorder(root, vals);
//         for (int i = 1; i < vals.size(); ++i) {
//             if (vals[i] <= vals[i - 1]) return false;
//         }
//         return true;
//     }

//     void inorder(TreeNode* node, vector<int>& vals) {
//         if (!node) return;
//         inorder(node->left, vals);
//         vals.push_back(node->val);
//         inorder(node->right, vals);
//     }

//     // Sum all nodes in a subtree
//     int sumTree(TreeNode* node) {
//         if (!node) return 0;
//         return node->val + sumTree(node->left) + sumTree(node->right);
//     }
// };