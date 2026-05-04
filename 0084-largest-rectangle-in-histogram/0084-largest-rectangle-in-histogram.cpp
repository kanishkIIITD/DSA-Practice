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
};