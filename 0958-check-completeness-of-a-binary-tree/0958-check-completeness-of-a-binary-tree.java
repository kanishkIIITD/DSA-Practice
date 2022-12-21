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
    public boolean solve(TreeNode root, int i, int node){
        if(root == null)
            return true;
        if(i >= node)
            return false;
        else{
            boolean left = solve(root.left, 2*i+1, node);
            boolean right = solve(root.right, 2*i+2, node);
            return (left && right);
        }
    }
    public int countNodes(TreeNode root){
        if(root == null)
            return 0;
        return 1 + countNodes(root.left) + countNodes(root.right);
    }
    public boolean isCompleteTree(TreeNode root) {
        int node = countNodes(root);
        return solve(root, 0, node);
    }
}