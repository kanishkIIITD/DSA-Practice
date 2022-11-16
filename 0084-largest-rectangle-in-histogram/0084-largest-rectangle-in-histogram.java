class Solution {
    public int[] nextSmall(int arr[], int n){
        Stack<Integer> st = new Stack<>();
        int ans[] = new int[n];
        st.push(-1);

        for(int i=n-1; i>=0; i--){
            int cur = arr[i];
            while(st.peek() != -1 && arr[st.peek()] >= cur)
                st.pop();

            ans[i] = st.peek();
            st.push(i);

        }  

        return ans;
    }
    public int[] prevSmall(int arr[], int n){
        Stack<Integer> st = new Stack<>();
        int ans[] = new int[n];
        st.push(-1);

        for(int i=0; i < n; i++){
            int cur = arr[i];
            while(st.peek() != -1 && arr[st.peek()] >= cur)
                st.pop();

            ans[i] = st.peek();
            st.push(i);

        }  

        return ans;
    }
    public int largestRectangleArea(int[] heights) {
        int n = heights.length;
        int next[] = new int [n];
        next = nextSmall(heights, n);
            
        int prev[] = new int[n];
        prev = prevSmall(heights, n);
        
        int area = Integer.MIN_VALUE;
        for(int i = 0; i < n; i++){
            int l = heights[i];
            if(next[i] == -1)
                next[i] = n;
            int b = next[i] - prev[i] - 1;
            int newArea = l*b;
            if(newArea > area)
                area = newArea; 
        }
        return area;
    }
}