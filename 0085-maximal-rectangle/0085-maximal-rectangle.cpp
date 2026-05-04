class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int area = 0;
        int n = heights.size();
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int currIdx = st.top(); st.pop();
                int psi = st.empty() ? -1 : st.top();
                int currArea = heights[currIdx] * (i - psi - 1);
                area = max(area, currArea);
            }
            st.push(i);
        }
        while(!st.empty()){
            int currIdx = st.top(); st.pop();
            int psi = st.empty() ? -1 : st.top();
            int currArea = heights[currIdx] * (n - psi - 1);
            area = max(area, currArea);
        }
        return area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        // vector<vector<int>> prefix(m, vector<int>(n));
        // for(int j = 0; j < n; j++){
        //     int sum = 0;
        //     for(int i = 0; i < m; i++){
        //         if(matrix[i][j] == '1')
        //             sum += 1;
        //         else
        //             sum = 0;
        //         prefix[i][j] = sum;
        //     }
        // }
        // int maxArea = 0;
        // for(int i = 0; i < m; i++){
        //     maxArea = max(maxArea, largestRectangleArea(prefix[i]));
        // }
        // return maxArea;

        vector<int> height(n);
        int maxArea = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
            }
            maxArea = max(maxArea, largestRectangleArea(height));
        }
        return maxArea;
    }
};