class Solution {
public:
    int getSmallerCount(vector<vector<int>>& grid, int t) {
        int n = grid.size(), m = grid[0].size();
        int cnt = 0;
        for(int r=0;r<n;r++) {
            cnt += lower_bound(grid[r].begin(), grid[r].end(), t) - grid[r].begin();
        }
        return cnt;
    }

    int matrixMedian(vector<vector<int>>& grid) {
        int l = 1, r = 1e6;
        int n = grid.size(), m = grid[0].size();
        int totalCnt = n * m, reqCnt = (totalCnt-1)/2;
        while(l < r) {
            int mid = (l+r+1)/2;
            int smallerCount = getSmallerCount(grid, mid);
            if(smallerCount <= reqCnt) l = mid;
            else r = mid-1;
        }
        return r;
    }
};