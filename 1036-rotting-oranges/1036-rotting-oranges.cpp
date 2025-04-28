class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<int,int>> q;
        // Push every rotten oranges in the queue
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
        int time = -1;
        // bfs
        while(!q.empty()){
            int levelSize = q.size();
            time++;
            for(int level = 0; level < levelSize; level++){
                auto [i,j] = q.front();
                q.pop();
                vector<int> dx = {-1, 0, 1, 0};
                vector<int> dy = {0, 1, 0, -1};
                for(int k = 0; k < 4; k++){
                    int nrow = i + dx[k];
                    int ncol = j + dy[k];
                    if(0 <= nrow && nrow < m && 0 <= ncol && ncol < n 
                    && grid[nrow][ncol] == 1 && !vis[nrow][ncol]){
                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            } 
        }
        // check if any orange is left unrotten
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0)
                    return -1;
            }
        }
        return time == -1 ? 0 : time;
    }
};