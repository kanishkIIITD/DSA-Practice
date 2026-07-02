class Solution {
public:
    struct help{
        int row;
        int col;
        int heal;
    };
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        queue<help> q;
        if(grid[0][0] == 1)
            health--;
        if (health <= 0) return false;
        q.push({0, 0, health});
        vector<vector<int>> vis(m, vector<int>(n, -1));
        vis[0][0] = health;
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            int r = front.row;
            int c = front.col;
            int h = front.heal;
            if(r == m-1 && c == n-1)
                return true;
            for(int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(0 <= nr && nr < m && 0 <= nc && nc < n){
                    int nextHealth = h - grid[nr][nc];
                    if (nextHealth > 0 && nextHealth > vis[nr][nc]) {
                        vis[nr][nc] = nextHealth;
                        q.push({nr, nc, nextHealth});
                    }
                }
            }
        }
        return false;
    }
};