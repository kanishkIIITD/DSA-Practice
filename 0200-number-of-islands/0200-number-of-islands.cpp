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
            
            vector<int> deltaRow = {-1, 0, 1, 0};
            vector<int> deltaCol = {0, 1, 0, -1};
            for(int k = 0; k < 4; k++){
                int nRow = i + deltaRow[k];
                int nCol = j + deltaCol[k];
                if(0 <= nRow && nRow < grid.size() 
                && 0 <= nCol && nCol < grid[0].size() 
                && grid[nRow][nCol] == '1' && !vis[nRow][nCol]){
                    vis[nRow][nCol] = 1;
                    q.push({nRow, nCol});
                }
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