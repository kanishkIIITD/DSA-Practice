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
class Pair{
    int height;
    int leftVal;
    Pair(){
        this.height = 0;
        this.leftVal = 0;
    }
}
class Solution {
    public Pair fast(TreeNode root){
        if(root == null)
            return new Pair();
        
        Pair left = fast(root.left);
        Pair right = fast(root.right);
        
        Pair ans = new Pair();
        ans.height = Math.max(left.height, right.height) + 1;
        
        if(ans.height == 1)
            ans.leftVal = root.val;
        else if(left.height >= right.height)
            ans.leftVal = left.leftVal;
        else
            ans.leftVal = right.leftVal;
        
        return ans;
    }
    public int findBottomLeftValue(TreeNode root) {
        Pair ans = fast(root);
        return ans.leftVal;
    }
}