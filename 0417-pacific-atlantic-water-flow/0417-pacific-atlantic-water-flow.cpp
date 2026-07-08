class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> p(n, vector<int>(m));
        vector<vector<int>> q(n, vector<int>(m));
        queue<pair<int, int>> q1;
        queue<pair<int, int>> q2;
        for(int i = 0; i < n; i++){
            p[i][0] = 1;
            q1.push({i, 0});
            q[i][m-1] = 1;
            q2.push({i, m-1});
        }
        for(int i = 0; i < m; i++){
            p[0][i] = 1;
            q1.push({0, i});
            q[n-1][i] = 1;
            q2.push({n-1, i});
        }
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
        while(!q1.empty()){
            auto [r, c] = q1.front(); q1.pop();
            for(int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(0 <= nr && nr < n && 0 <= nc && nc < m && !p[nr][nc] && mat[nr][nc] >= mat[r][c]){
                    p[nr][nc] = 1;
                    q1.push({nr, nc});
                }
            }
        }
        while(!q2.empty()){
            auto [r, c] = q2.front(); q2.pop();
            for(int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(0 <= nr && nr < n && 0 <= nc && nc < m && !q[nr][nc] && mat[nr][nc] >= mat[r][c]){
                    q[nr][nc] = 1;
                    q2.push({nr, nc});
                }
            }
        }
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(p[i][j] && q[i][j])
                    ans.push_back({i, j});
            }
        }
        return ans;
    }
};