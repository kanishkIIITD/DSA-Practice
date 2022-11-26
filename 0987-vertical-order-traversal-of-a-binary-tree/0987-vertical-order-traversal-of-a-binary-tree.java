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
    class pair{
        TreeNode node;
        int x;
        int y;
        public pair(int x, int y, TreeNode n){
            this.x = x;
            this.y = y;
            this.node = n;
        }
    }

    public List<List<Integer>> verticalTraversal(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        if(root == null)return res; // corner case
		
        Map<Integer, List<pair>> map = new HashMap<>();
        Queue<pair> queue = new LinkedList<>(); //BFS
        queue.add(new pair(0,0,root));
        int left = 0; // leftmost x 
        int right = 0; // rightmost x
        
        while(!queue.isEmpty()){
            pair temp = queue.poll();
            left = Math.min(left, temp.x);
            right = Math.max(right,temp.x);
            
            if(!map.containsKey(temp.x)){
                map.put(temp.x, new ArrayList<>());
            }
            map.get(temp.x).add(new pair(temp.x, temp.y, temp.node));
            if(temp.node.left != null)queue.add(new pair(temp.x-1, temp.y+1, temp.node.left));
            if(temp.node.right != null)queue.add(new pair(temp.x+1, temp.y+1, temp.node.right));
        }
        
        for(int i=left; i<=right; i++){
            Collections.sort(map.get(i), (a,b)-> a.y == b.y ? a.node.val - b.node.val : a.y - b.y); // sort the node that have same y value
            List<Integer> templist = new ArrayList<>();
            for(int j=0; j< map.get(i).size(); j++){
                templist.add(map.get(i).get(j).node.val);
            }
            res.add(templist);
        }
        return res;
    }
}