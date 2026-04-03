class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; 
        pq.push({0, {0, 0}});
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};
        while(!pq.empty()){
            int distance = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if(row == m - 1 && col == n - 1) {
                return distance;
            }
            if(distance > dist[row][col]) {
                continue;
            }
            for(int i = 0; i < 4; i++){
                int nr = row + dx[i];
                int nc = col + dy[i];
                if(0 <= nr && nr < m && 0 <= nc && nc < n && max(distance, abs(heights[nr][nc] - heights[row][col])) < dist[nr][nc]){
                    dist[nr][nc] = max(distance, abs(heights[nr][nc] - heights[row][col]));
                    pq.push({dist[nr][nc], {nr, nc}});
                }
            }
        }
        return 0;
    }
};