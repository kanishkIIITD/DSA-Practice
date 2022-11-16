//{ Driver Code Starts
import java.util.*;

class FindMinCost
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t > 0)
		{
			int n = sc.nextInt();
			int m = sc.nextInt();
			int arr[][] = new int[n][m];
			for(int i=0; i<n; i++)
			{
				for(int j=0; j<m; j++ )
				{
					arr[i][j] = sc.nextInt();
				}
			}
			System.out.println(new Solution().maxArea(arr, n, m));
		t--;
		}
	}
}
// } Driver Code Ends


/*Complete the function given below*/
class Solution {
    
    public int[] nextSmall(int arr[], int n) {
        Stack<Integer> st = new Stack<>();
        int ans[] = new int[n];
        st.push(-1);

        for (int i = n - 1; i >= 0; i--) {
            int cur = arr[i];
            while (st.peek() != -1 && arr[st.peek()] >= cur) st.pop();

            ans[i] = st.peek();
            st.push(i);
        }

        return ans;
    }

    public int[] prevSmall(int arr[], int n) {
        Stack<Integer> st = new Stack<>();
        int ans[] = new int[n];
        st.push(-1);

        for (int i = 0; i < n; i++) {
            int cur = arr[i];
            while (st.peek() != -1 && arr[st.peek()] >= cur) st.pop();

            ans[i] = st.peek();
            st.push(i);
        }

        return ans;
    }

    public int largestRectangleArea(int[] heights) {
        int n = heights.length;
        int next[] = new int[n];
        next = nextSmall(heights, n);

        int prev[] = new int[n];
        prev = prevSmall(heights, n);

        int area = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            int l = heights[i];
            if (next[i] == -1) next[i] = n;
            int b = next[i] - prev[i] - 1;
            int newArea = l * b;
            if (newArea > area) area = newArea;
        }
        return area;
    }
    
    public int maxArea(int M[][], int n, int m) {
        // add code here.
       
        int cur[] = M[0];
        int area = largestRectangleArea(cur);
        
        for(int i = 1; i < n; i++){
            int row[] = M[i];
            for(int j = 0; j < m; j++){
                if(row[j] == 0)
                    cur[j] = 0;
                else
                    cur[j] ++;
            }
            int newArea = largestRectangleArea(cur);
            if(newArea > area)
                area = newArea;
        }
        return area;
    }
}