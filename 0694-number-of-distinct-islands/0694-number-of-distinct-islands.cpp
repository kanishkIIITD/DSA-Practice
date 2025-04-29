class Solution {
public:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid, unordered_set<string>&st, int m, int n, string& s){
        vis[row][col] = 1;
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};
        string dirs = "URDL";
        for(int i = 0; i < 4; i++){
            int nrow = row + dx[i];
            int ncol = col + dy[i];
            if(0 <= nrow && nrow < m && 0 <= ncol && ncol < n && grid[nrow][ncol] == 1 && !vis[nrow][ncol]){
                s += dirs[i]; 
                dfs(nrow, ncol, vis, grid, st, m, n, s);
                s += "B";
            }
        }
    }
    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        unordered_set<string> st;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    string s = "";
                    dfs(i, j, vis, grid, st, m, n, s);
                    st.insert(s);
                }
            }
        }
        return st.size();
    }
};