class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>> vis(m, vector<int>(n));
        int originalColor = image[sr][sc];
        queue<pair<int, int>> q;
        q.push({sr, sc});
        vis[sr][sc] = 1;
        image[sr][sc] = color;
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            vector<int> dx = {-1, 0, 1, 0};
            vector<int> dy = {0, -1, 0, 1};
            for(int i = 0; i < 4; i++){
                int nr = row + dx[i];
                int nc = col + dy[i];
                if(0 <= nr && nr < m && 0 <= nc && nc < n && image[nr][nc] == originalColor && !vis[nr][nc]){
                    q.push({nr, nc});
                    vis[nr][nc] = 1;
                    image[nr][nc] = color;
                }
            }
        }
        return image;
    }
};