//{ Driver Code Starts
//Initial Template for Java


import java.util.LinkedList;
import java.util.Queue;
import java.io.*;
import java.util.*;

class Node {
	int data;
	Node left;
	Node right;

	Node(int data) {
		this.data = data;
		left = null;
		right = null;
	}
}

class GfG {

	static Node buildTree(String str) {

		if (str.length() == 0 || str.charAt(0) == 'N') {
			return null;
		}

		String ip[] = str.split(" ");
		// Create the root of the tree
		Node root = new Node(Integer.parseInt(ip[0]));
		// Push the root to the queue

		Queue<Node> queue = new LinkedList<>();

		queue.add(root);
		// Starting from the second element

		int i = 1;
		while (queue.size() > 0 && i < ip.length) {

			// Get and remove the front of the queue
			Node currNode = queue.peek();
			queue.remove();

			// Get the current node's value from the string
			String currVal = ip[i];

			// If the left child is not null
			if (!currVal.equals("N")) {

				// Create the left child for the current node
				currNode.left = new Node(Integer.parseInt(currVal));
				// Push it to the queue
				queue.add(currNode.left);
			}

			// For the right child
			i++;
			if (i >= ip.length)
				break;

			currVal = ip[i];

			// If the right child is not null
			if (!currVal.equals("N")) {

				// Create the right child for the current node
				currNode.right = new Node(Integer.parseInt(currVal));

				// Push it to the queue
				queue.add(currNode.right);
			}
			i++;
		}

		return root;
	}

	static void printInorder(Node root) {
		if (root == null)
			return;

		printInorder(root.left);
		System.out.print(root.data + " ");

		printInorder(root.right);
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int t = Integer.parseInt(br.readLine());

		while (t > 0) {
			String s = br.readLine();
			int target = Integer.parseInt(br.readLine());
			Node root = buildTree(s);

			Solution g = new Solution();
			System.out.println(g.minTime(root, target));
			t--;

		}
	}
}



// } Driver Code Ends


//User function Template for Java

class Solution
{
    /*class Node {
    	int data;
    	Node left;
    	Node right;
    
    	Node(int data) {
    		this.data = data;
    		left = null;
    		right = null;
    	}
    }*/
    
    Node nodeToParentMapping(Node root, int target, Map<Node, Node> nodeToParent, Map<Node, Boolean> visited){
        Queue<Node> q = new LinkedList<>();
        Node res = null;
        
        q.add(root);
        nodeToParent.put(root, null);
        visited.put(root, false);
        
        while(!q.isEmpty()){
            Node frontNode = q.poll();
            if(frontNode.data == target)
                res = frontNode;
            
            if(frontNode.left != null){
                nodeToParent.put(frontNode.left, frontNode);
                visited.put(frontNode.left, false);
                q.add(frontNode.left);
            }
            
            if(frontNode.right != null){
                nodeToParent.put(frontNode.right, frontNode);
                visited.put(frontNode.right, false);
                q.add(frontNode.right);
            }
        }
        return res;
    }
    
    int burn(Node targetNode, Map<Node, Node> nodeToParent, Map<Node, Boolean> visited){
        
        Queue<Node> q = new LinkedList<>();
        
        q.add(targetNode);
        visited.replace(targetNode, true);
        
        int ans = 0;
        while(!q.isEmpty()){
            int size = q.size();
            int flag = 0;
            for(int i = 0; i < size; i++){
                Node front = q.poll();
                
                if(front.left != null && !visited.get(front.left)){
                    q.add(front.left);
                    visited.replace(front.left, true);
                    flag = 1;
                }
                if(front.right != null && !visited.get(front.right)){
                    q.add(front.right);
                    visited.replace(front.right, true);
                    flag = 1;
                }
                if(nodeToParent.get(front) != null && !visited.get(nodeToParent.get(front))){
                    q.add(nodeToParent.get(front));
                    visited.replace(nodeToParent.get(front), true);
                    flag = 1;
                }
            }
            if(flag == 1)
                ans++;
        }
        return ans;
    }
    public int minTime(Node root, int target) {
        Map<Node, Node> nodeToParent = new HashMap<>();
        Map<Node, Boolean> visited = new HashMap<Node, Boolean>();
        Node targetNode = nodeToParentMapping(root, target, nodeToParent, visited);
        int ans = burn(targetNode, nodeToParent, visited);
        return ans;
    }
}