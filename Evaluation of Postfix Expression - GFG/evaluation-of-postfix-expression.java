//{ Driver Code Starts
import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
    
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine().trim());
		while(t-->0){
		    System.out.println(new Solution().evaluatePostFix(br.readLine().trim()));
		}
	}
}
// } Driver Code Ends


class Solution
{
    //Function to evaluate a postfix expression.
    public static int evaluatePostFix(String S)
    {
        // Your code here
        Stack<Integer> st = new Stack<Integer>();
        for(int i = 0; i < S.length(); i++){
            char ch = S.charAt(i);
            if(Character.isDigit(ch))
                st.push(ch- '0');
            
            else{
                int val1 = st.pop();
                int val2 = st.pop();
                
                switch(ch)
                {
                    case '+':
                    st.push(val2+val1);
                    break;
                     
                    case '-':
                    st.push(val2- val1);
                    break;
                     
                    case '/':
                    st.push(val2/val1);
                    break;
                     
                    case '*':
                    st.push(val2*val1);
                    break;
                }
            }
        }
        return st.peek();
    }
}