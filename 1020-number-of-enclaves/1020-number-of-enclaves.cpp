class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n));
        int ans = 0;
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++){
            if(grid[i][0] == 1){
                q.push({i, 0});
                vis[i][0] = 1;
            }
            if(grid[i][n-1] == 1){
                q.push({i, n-1});
                vis[i][n-1] = 1;
            }
        }
        for(int i = 1; i < n-1; i++){
            if(grid[0][i] == 1){
                q.push({0, i});
                vis[0][i] = 1;
            }
            if(grid[m-1][i] == 1){
                q.push({m-1, i});
                vis[m-1][i] = 1;
            }
        }
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++){
                int nr = row + dx[i];
                int nc = col + dy[i];
                if(0 <= nr && nr < m && 0 <= nc && nc < n && grid[nr][nc] == 1 && !vis[nr][nc]){
                    q.push({nr, nc});
                    vis[nr][nc] = 1;
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && !vis[i][j])
                    ans++;
            }
        }
        return ans;
    }
};