class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1)
            return -1;
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        dist[0][0] = 1;
        q.push({0, 0});
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int dx = -1; dx <= 1; dx++){
                for(int dy = -1; dy <= 1; dy++){
                    int nr = row + dx;
                    int nc = col + dy;
                    if(0 <= nr && nr < n && 0 <= nc && nc < n && grid[nr][nc] == 0 && dist[row][col] + 1 < dist[nr][nc]){
                        dist[nr][nc] = dist[row][col] + 1;
                        q.push({nr, nc});
                    }
                }
            }
        }
        if(dist[n-1][n-1] == INT_MAX)
            return -1;
        return dist[n-1][n-1];
    }
};