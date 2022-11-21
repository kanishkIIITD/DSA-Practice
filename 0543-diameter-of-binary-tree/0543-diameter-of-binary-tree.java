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
    public int diameterOfBinaryTree(TreeNode root) {
        if(root==null)return 0;
   
        DiaPair ans=findDiameter(root);
        
        return ans.diameter;
    }
    
    public DiaPair findDiameter(TreeNode root ){  //O(n)
        if(root==null){
            return new DiaPair(-1, 0);
        }
        
        DiaPair lhs=findDiameter(root.left);
        DiaPair rhs=findDiameter(root.right);
        
        DiaPair myPair=new DiaPair();
        myPair.diameter=Math.max(lhs.height+rhs.height+2, Math.max(lhs.diameter, rhs.diameter));
        myPair.height=Math.max(lhs.height, rhs.height)+1;
        
        return myPair;
    }
}
class DiaPair{
    int height;
    int diameter;
    
    public DiaPair(){}
    
    public DiaPair(int height, int diameter){
        this.height=height;
        this.diameter=diameter;
    }
}