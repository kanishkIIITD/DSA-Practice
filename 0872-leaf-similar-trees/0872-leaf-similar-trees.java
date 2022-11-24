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
    void inorder(TreeNode root, ArrayList<Integer> leaf){
        if(root == null)
            return;
        if(root.left == null && root.right  == null)
            leaf.add(root.val);
        inorder(root.left, leaf);
        inorder(root.right, leaf);
    }
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        ArrayList<Integer> leaf1 = new ArrayList<Integer>();
        ArrayList<Integer> leaf2 = new ArrayList<Integer>();
        inorder(root1, leaf1);
        inorder(root2, leaf2);
        if(leaf1.size() != leaf2.size())
            return false;
        else{
            for(int i = 0; i < leaf1.size(); i++){
                if(leaf1.get(i) != leaf2.get(i))
                    return false;
            }
            return true;
        }
        
    }
}