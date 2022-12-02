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
    ArrayList<Integer> inorder = new ArrayList<>();
    public void inorder(TreeNode root){
        if(root == null)
            return;
        inorder(root.left);
        inorder.add(root.val);
        inorder(root.right);
    }
    public boolean isValidBST(TreeNode root) {

        inorder(root);

        for (int i=0; i<inorder.size()-1; i++) {
            if (inorder.get(i) >= inorder.get(i+1)) {
                return false;
            }
        }
        return true;
    }
}