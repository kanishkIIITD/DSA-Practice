class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>
            pq;
        vector<vector<int>> dist(m, vector<int>(n, 1e9));
        pq.push({0, {0, 0}});
        dist[0][0] = 0;
        
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};

        while(!pq.empty()){
            int d = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            for(int i = 0; i < 4; i++){
                int nrow = row + dx[i];
                int ncol = col + dy[i];
                if(0 <= nrow && nrow < m && 0 <= ncol && ncol < n){
                    int effort = max(d, abs(abs(heights[nrow][ncol] - heights[row][col])));
                    if(effort < dist[nrow][ncol]){
                        dist[nrow][ncol] = effort;
                        pq.push({effort, {nrow, ncol}});
                    }
                }
            }
        }
        return dist[m-1][n-1];
    }
};