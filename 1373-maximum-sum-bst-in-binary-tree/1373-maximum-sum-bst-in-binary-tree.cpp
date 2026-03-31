class NodeValue {
public:
    int maxNode, minNode, sum;
    // Constructor takes maxNode, minNode, and the sum of the current subtree
    NodeValue(int maxNode, int minNode, int sum){
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->sum = sum;
    }
};

class Solution {
private:
    int maxSum = 0; // Tracks the global maximum sum across all valid BSTs

    NodeValue maxSumBSTHelper(TreeNode* root){
        // Base case: empty tree. 
        // maxNode = INT_MIN, minNode = INT_MAX guarantees leaves will pass the BST check.
        if(!root)
            return NodeValue(INT_MIN, INT_MAX, 0);
        
        auto left = maxSumBSTHelper(root->left);
        auto right = maxSumBSTHelper(root->right);

        // Check if the current tree is a valid BST
        if(left.maxNode < root->val && root->val < right.minNode){
            
            // It is a valid BST! Calculate its sum.
            int currentSum = root->val + left.sum + right.sum;
            
            // Update the global maximum sum (an empty BST sum is 0, so maxSum starts at 0)
            maxSum = max(maxSum, currentSum);
            
            // Return updated boundaries: (maxNode, minNode, sum)
            return NodeValue(max(root->val, right.maxNode), 
                             min(root->val, left.minNode), 
                             currentSum);
        }
        
        // If invalid, return boundaries that force the parent's BST check to fail.
        // maxNode = INT_MAX and minNode = INT_MIN guarantees failure.
        return NodeValue(INT_MAX, INT_MIN, 0); 
    }

public:
    int maxSumBST(TreeNode* root) {
        maxSumBSTHelper(root);
        return maxSum;
    }
};