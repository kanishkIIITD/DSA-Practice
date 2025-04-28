class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        // bfs
        queue<pair<int, int>> q;
        q.push({sr, sc});
        vis[sr][sc] = 1;
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            vector<int> deltaRow = {-1, 0, 1, 0};
            vector<int> deltaCol = {0, 1, 0, -1};
            for(int k = 0; k < 4; k++){
                int nrow = row + deltaRow[k];
                int ncol = col + deltaCol[k];
                if(0 <= nrow && nrow < m && 0 <= ncol && ncol < n 
                && image[row][col] == image[nrow][ncol] && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }

            image[row][col] = color;
        }
        return image;
    }
};