class Solution {
public:
    void reverseArrays(vector<int> &a, vector<int> &b, int start, int end){
        for(int i = start; i <= end; i++)
            swap(a[i], b[i]);
        return;
    }
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int up = x, down = x+k-1;
        while(up <= down){
            reverseArrays(grid[up], grid[down], y, y+k-1);
            up++;down--;
        }
        return grid;
    }
};