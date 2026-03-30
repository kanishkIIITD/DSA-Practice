class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        // Base case: the key was not found or the tree is empty
        if (!root) return nullptr;

        // 1. Search for the node
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } 
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } 
        // 2. Node found! Let's delete it.
        else {
            // Case 1 & 2: Node has 0 or 1 child
            if (!root->left) {
                TreeNode* rightChild = root->right;
                delete root;
                return rightChild;
            } 
            else if (!root->right) {
                TreeNode* leftChild = root->left;
                delete root;
                return leftChild;
            }
            
            // Case 3: Node has 2 children
            // Find the inorder successor (smallest node in the right subtree)
            TreeNode* successor = root->right;
            while (successor->left) {
                successor = successor->left;
            }
            
            // Replace the current node's value with the successor's value
            root->val = successor->val;
            
            // Delete the successor node from the right subtree
            root->right = deleteNode(root->right, successor->val);
        }
        
        return root;
    }
};