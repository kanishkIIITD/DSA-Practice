//{ Driver Code Starts
import java.util.*;

class Node {
    int data;
    Node left;
    Node right;

    Node(int value) {
        data = value;
        left = null;
        right = null;
    }
}

class InorderPostorderToTree {
    public void preOrder(Node root) {
        if (root == null) return;

        System.out.print(root.data + " ");
        preOrder(root.left);

        preOrder(root.right);
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        InorderPostorderToTree ip = new InorderPostorderToTree();
        int T = sc.nextInt();
        while (T > 0) {
            int n = sc.nextInt();
            int inorder[] = new int[n];
            int postorder[] = new int[n];
            for (int i = 0; i < n; i++) inorder[i] = sc.nextInt();
            for (int i = 0; i < n; i++) postorder[i] = sc.nextInt();
            GfG g = new GfG();
            Node root = g.buildTree(inorder, postorder, n);
            ip.preOrder(root);
            System.out.println();

            T--;
        }
    }
}

// } Driver Code Ends


/* Tree node structure
class Node
{
    int data;
    Node left;
    Node right;

        Node(int value)
    {
        data = value;
        left = null;
        right = null;
    }
}*/


class GfG
{
    int postOrderIndex = 0;
    public int findPosition(int inorder[], int element, int n){
        for(int i = 0; i < n; i++)
            if(inorder[i] == element)
                return i;
        return -1;
    }
    public Node solve(int inorder[], int postorder[], int n, int inOrderStart, int inOrderEnd){
        if(postOrderIndex < 0 || inOrderStart > inOrderEnd)
            return null;
        
        int element = postorder[postOrderIndex--];
        Node root = new Node(element);
        int position = findPosition(inorder, element, n);
        
        root.right = solve(inorder, postorder, n, position+1, inOrderEnd);
        root.left = solve(inorder, postorder, n, inOrderStart, position-1);

        return root;
    }
    //Function to return a tree created from postorder and inoreder traversals.
    Node buildTree(int in[], int post[], int n) {
        postOrderIndex = n-1;
        Node ans = solve(in, post, n, 0, n-1);
        return ans;
    }
}
