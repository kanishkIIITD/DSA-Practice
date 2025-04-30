class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> vis(m, vector<int>(n, -1));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    vis[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};

        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for(int k = 0; k < 4; k++){
                int nrow = i + dx[k];
                int ncol = j + dy[k];
                if(0 <= nrow && nrow < m && 0 <= ncol && ncol < n && vis[nrow][ncol] == -1){
                    vis[nrow][ncol] = vis[i][j] + 1;
                    q.push({nrow, ncol});
                }
            }
        }

        return vis;
    }
};