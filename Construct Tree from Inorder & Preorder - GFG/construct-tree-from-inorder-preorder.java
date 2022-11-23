//{ Driver Code Starts
import java.util.*;
import java.io.*;
class Node
{
    int data; 
    Node left, right;
    Node(int key)
    {
        data = key;
        left = right = null;
    }
}

class GFG
{
    public static void main (String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        while(t-- > 0)
        {
            int n = sc.nextInt();
            Node root = null;
            int inorder[] = new int[n];
            int preorder[] = new int[n];
            for(int i = 0; i < n; i++)
              inorder[i] = sc.nextInt();
              
            for(int i = 0; i < n; i++)
              preorder[i] = sc.nextInt();
              
            Solution ob = new Solution();
            root = ob.buildTree(inorder, preorder, n);
            postOrdrer(root);
            System.out.println();
        }
    }
    
    public static void postOrdrer(Node root)
    {
        if(root == null)
          return;
          
        postOrdrer(root.left);
        postOrdrer(root.right);
        System.out.print(root.data + " ");
    }
}
// } Driver Code Ends


class Solution
{
    int preOrderIndex = 0;
    public int findPosition(int inorder[], int element, int n){
        for(int i = 0; i < n; i++)
            if(inorder[i] == element)
                return i;
        return -1;
    }
    public Node solve(int inorder[], int preorder[], int n, int inOrderStart, int inOrderEnd){
        if(preOrderIndex >= n || inOrderStart > inOrderEnd)
            return null;
        
        int element = preorder[preOrderIndex++];
        Node root = new Node(element);
        int position = findPosition(inorder, element, n);
        
        root.left = solve(inorder, preorder, n, inOrderStart, position-1);
        root.right = solve(inorder, preorder, n, position+1, inOrderEnd);
        
        return root;
    }
    public Node buildTree(int inorder[], int preorder[], int n)
    {
        Node ans = solve(inorder, preorder, n, 0, n-1);
        return ans;
    }
}
