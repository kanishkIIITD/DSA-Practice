/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int height(TreeNode root){
        if(root == null)
            return 0;
        
        int left = height(root.left);
        int right = height(root.right);
        int ans = Math.max(left, right) + 1;
        return ans;
    }
    public int diameterOfBinaryTree(TreeNode root) {
        if(root == null)
            return 0;
        
        int option1 = diameterOfBinaryTree(root.left);
        int option2 = diameterOfBinaryTree(root.right);
        int option3 = height(root.left) + height(root.right);
        
        int ans1 = Math.max(option1, option2);
        int ans = Math.max(option3, ans1);
        return ans;
    }
}