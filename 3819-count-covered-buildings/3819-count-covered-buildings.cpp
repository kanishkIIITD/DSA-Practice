class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, vector<int>> rows;   // {row: sorted columns}
        unordered_map<int, vector<int>> cols;   // {col: sorted rows}
        
        // Populate rows and cols (O(m log m))
        for (auto& b : buildings) {
            int x = b[0]-1, y = b[1]-1;  // Convert to 0-based
            rows[x].push_back(y);
            cols[y].push_back(x);
        }
        
        // Sort all entries once (O(m log m))
        for (auto& [r, cs] : rows) sort(cs.begin(), cs.end());
        for (auto& [c, rs] : cols) sort(rs.begin(), rs.end());
        
        int count = 0;
        for (auto& b : buildings) {
            int x = b[0]-1, y = b[1]-1;
            
            // Check left (exists column < y in same row)
            auto& row = rows[x];
            auto it_left = lower_bound(row.begin(), row.end(), y);
            bool has_left = (it_left != row.begin());
            
            // Check right (exists column > y in same row)
            auto it_right = upper_bound(row.begin(), row.end(), y);
            bool has_right = (it_right != row.end());
            
            // Check up (exists row < x in same column)
            auto& col = cols[y];
            auto it_up = lower_bound(col.begin(), col.end(), x);
            bool has_up = (it_up != col.begin());
            
            // Check down (exists row > x in same column)
            auto it_down = upper_bound(col.begin(), col.end(), x);
            bool has_down = (it_down != col.end());
            
            if (has_left && has_right && has_up && has_down) {
                count++;
            }
        }
        return count;
    }
};