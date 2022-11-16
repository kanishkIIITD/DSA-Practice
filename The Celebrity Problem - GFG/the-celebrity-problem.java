//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*; 

class GFG{
    public static void main(String args[]) throws IOException { 
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t>0)
        {
            int N = sc.nextInt();
            int M[][] = new int[N][N];
            for(int i=0; i<N; i++)
            {
                for(int j=0; j<N; j++)
                {
                    M[i][j] = sc.nextInt();
                }
            }
            System.out.println(new Solution().celebrity(M,N));
            t--;
        }
    } 
} 
// } Driver Code Ends


//User function Template for Java


class Solution
{ 
    //Function to find if there is a celebrity in the party or not.
    int celebrity(int M[][], int n)
    {
    	// code here 
    	Stack<Integer> s = new Stack<Integer>();
    	for(int i = 0; i < n; i++)
    	    s.push(i);
        
        while(s.size() != 1){
            int A = s.peek();
            s.pop();
            int B = s.peek();
            s.pop();
            
            if(M[A][B] == 1)
                s.push(B);
            
            else if(M[B][A] == 1)
                s.push(A);
        }
        if(s.empty())
            return -1;
        else{
            int last = s.pop();
            boolean row = true;
            boolean col = true;
            for(int j = 0; j < n; j++){
                if(M[last][j] == 1){
                    row = false;
                    break;
                }
            }
            for(int i = 0; i < n; i++){
                if(M[i][last] == 0 && i != last){
                    col = false;
                    break;
                }
            }
            if(row && col)
                return last;
            else 
                return -1;
        }
    }
}