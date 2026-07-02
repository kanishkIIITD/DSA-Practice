class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, 1e9));
        deque<pair<int, int>> dq;
        dist[0][0] = grid[0][0];
        dq.push_back({0, 0});
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        while(!dq.empty()){
            auto [r, c] = dq.front();
            dq.pop_front();
            if(r == m-1 && c == n-1)
                return health - dist[r][c] > 0;
            for(int i = 0; i < 4; i++){
                int nr = r + dr[i], nc = c + dc[i];
                if(0 <= nr && nr < m && 0 <= nc && nc < n){
                    int cost = grid[nr][nc];
                    if(dist[r][c] + cost < dist[nr][nc]){
                        dist[nr][nc] = dist[r][c] + cost;
                        if(cost == 0)
                            dq.push_front({nr, nc});
                        else
                            dq.push_back({nr, nc});
                    }
                }
            }
        }
        return false;
    }
};