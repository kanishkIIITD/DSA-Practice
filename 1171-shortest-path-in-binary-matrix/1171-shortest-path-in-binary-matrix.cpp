class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (grid[0][0] || grid[m-1][n-1]) return -1;
        
        queue<pair<int, int>> q;
        vector<vector<int>> dirs = {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};
        
        grid[0][0] = 1; // Mark visited
        q.push({0, 0});
        
        int steps = 1;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [x, y] = q.front(); q.pop();
                if (x == m-1 && y == n-1) return steps;
                
                for (auto& dir : dirs) {
                    int nx = x + dir[0], ny = y + dir[1];
                    if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 0) {
                        grid[nx][ny] = 1; // Mark visited
                        q.push({nx, ny});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
