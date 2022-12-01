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
    public int minValue(TreeNode root){
        TreeNode temp = root;
        int mini = 0;
        while(temp != null){
            mini = temp.val;
            temp = temp.left;
        }
        return mini;
    }
    public TreeNode deleteNode(TreeNode root, int key) {
        if(root == null)
            return root;
        
        if(root.val == key){
            if(root.left == null && root.right == null){
                root = null;
                return root;
            }
            
            else if(root.left == null && root.right != null){
                TreeNode temp = root.right;
                root = null;
                return temp;
            }
            
            else if(root.left != null && root.right == null){
                TreeNode temp = root.left;
                root = null;
                return temp;
            }
            
            // if(root.left != null && root.right != null){
            else{
                int mini = minValue(root.right);
                root.val = mini;
                root.right = deleteNode(root.right, mini);
                return root;
            }
        }
        
        else if(root.val > key){
            root.left = deleteNode(root.left, key);
            return root;
        }
        
        else{
            root.right = deleteNode(root.right, key);
            return root;
        } 
    }
}