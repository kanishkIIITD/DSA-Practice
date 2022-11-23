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
    int preOrderIndex = 0;
    public int findPosition(int inorder[], int element, int n){
        for(int i = 0; i < n; i++)
            if(inorder[i] == element)
                return i;
        return -1;
    }
    public TreeNode solve(int inorder[], int preorder[], int n, int inOrderStart, int inOrderEnd){
        if(preOrderIndex >= n || inOrderStart > inOrderEnd)
            return null;
        
        int element = preorder[preOrderIndex++];
        TreeNode root = new TreeNode(element);
        int position = findPosition(inorder, element, n);
        
        root.left = solve(inorder, preorder, n, inOrderStart, position-1);
        root.right = solve(inorder, preorder, n, position+1, inOrderEnd);
        
        return root;
    }
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        int n = preorder.length;
        TreeNode ans = solve(inorder, preorder, n, 0, n-1);
        return ans;
    }
}