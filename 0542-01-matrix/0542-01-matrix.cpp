class Solution {
public:
    void bfs(int row, int col, vector<vector<int>>& mat, vector<vector<int>>& vis, vector<vector<int>>& ans, int m, int n){
        vis[row][col] = 1;
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {row, col}});
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};
        while(!q.empty()){
            int dist = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            for(int i = 0; i < 4; i++){
                int nr = row + dx[i];
                int nc = col + dy[i];
                if(0 <= nr && nr < m && 0 <= nc && nc < n && mat[nr][nc] != 0 && !vis[nr][nc]){
                    vis[nr][nc] = 1;
                    q.push({dist+1, {nr, nc}});
                }
            }
        }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(); int n = mat[0].size();
        vector<vector<int>> vis(m, vector<int>(n));
        vector<vector<int>> ans(m, vector<int>(n));
        queue<pair<int, pair<int, int>>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    q.push({0, {i, j}});
                    vis[i][j] = 1;
                }
            }
        }
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};
        while(!q.empty()){
            int dist = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            ans[row][col] = dist;
            for(int i = 0; i < 4; i++){
                int nr = row + dx[i];
                int nc = col + dy[i];
                if(0 <= nr && nr < m && 0 <= nc && nc < n && !vis[nr][nc]){
                    vis[nr][nc] = 1;
                    q.push({dist+1, {nr, nc}});
                }
            }
        }
        return ans;
    }
};