class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n));
        queue<pair<int, int>> q;
        int freshCount = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                    vis[i][j] = 1;
                }
                if(grid[i][j] == 1)
                    freshCount++;
            }
        }
        if(freshCount == 0) return 0;
        int time = 0;
        while(!q.empty()){
            bool rottedThisMin = false;
            int size = q.size();
            for(int j = 0; j < size; j++){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                vector<int> dx = {-1, 0, 1, 0};
                vector<int> dy = {0, 1, 0, -1};
                for(int i = 0; i < 4; i++){
                    int nr = row + dx[i];
                    int nc = col + dy[i];
                    if(0 <= nr && nr < m && 0 <= nc && nc < n && grid[nr][nc] != 0 && !vis[nr][nc]){
                        q.push({nr, nc});
                        vis[nr][nc] = 1;
                        grid[nr][nc] = 2;
                        rottedThisMin = true;
                        freshCount--;
                    }
                }
            }
            if(rottedThisMin)
                time++;
        }
        if(freshCount >= 1)
            return -1;
        return time;
    }
};