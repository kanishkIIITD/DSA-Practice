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
    int count = 0;
    int m = 1000000007;
    public void solve(TreeNode root, int targetSum, ArrayList<Integer> path){
        if(root == null)
            return ;
        
        path.add(root.val);
        
        int sum = 0;
        for(int i = path.size()-1; i >= 0; i--){
            sum = (sum + path.get(i))%m;
            if(sum == targetSum)
                count++;
        }
        
        solve(root.left, targetSum, path);
        solve(root.right, targetSum, path);

        path.remove(path.size()-1);
    }
    public int pathSum(TreeNode root, int targetSum) {
        ArrayList<Integer> path = new ArrayList<>();
        solve(root, targetSum ,path);
        return count;
    }
}