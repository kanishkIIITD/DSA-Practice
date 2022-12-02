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
    public boolean solve(TreeNode root, long min, long max){
        if(root == null)
            return true;
        
        if((long)root.val > min && (long)root.val < max){
            boolean left = solve(root.left, min, (long)root.val);
            boolean right = solve(root.right, (long)root.val, max);
            return left && right;
        }
        else 
            return false;
    }
    public boolean isValidBST(TreeNode root) {
        return solve(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }
}