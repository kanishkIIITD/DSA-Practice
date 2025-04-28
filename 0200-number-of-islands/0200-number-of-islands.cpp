class Solution {
public:
    void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid){
        queue<pair<int, int>> q;
        q.push({row,col});
        vis[row][col] = 1;
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            // LEFT
            if(j-1 >= 0 && grid[i][j-1] == '1' && !vis[i][j-1]){
                vis[i][j-1] = 1;
                q.push({i, j-1});
            }
            // RIGHT
            if(j+1 < grid[0].size() && grid[i][j+1] == '1' && !vis[i][j+1]){
                vis[i][j+1] = 1;
                q.push({i, j+1});
            }
            // UP
            if(i-1 >= 0 && grid[i-1][j] == '1' && !vis[i-1][j]){
                vis[i-1][j] = 1;
                q.push({i-1, j});
            }
            // DOWN
            if(i+1 < grid.size() && grid[i+1][j] == '1' && !vis[i+1][j]){
                vis[i+1][j] = 1;
                q.push({i+1, j});
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));
        int islands = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    bfs(i, j, vis, grid);
                    islands++;
                }
            }
        }
        return islands;
    }
};