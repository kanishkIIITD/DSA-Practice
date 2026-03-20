class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int low = 0, high = m-1, mid;
        while(low <= high){
            mid = low + (high - low) / 2;
            auto maxiIt = max_element(mat[mid].begin(), mat[mid].end());
            int maxi = *maxiIt;
            int maxiIdx = distance(mat[mid].begin(), maxiIt);
            int up = (mid-1 < 0) ? -1 : mat[mid-1][maxiIdx];
            int down = (mid+1 >= m) ? -1 : mat[mid+1][maxiIdx];
            if(maxi > up && maxi > down)
                return {mid, maxiIdx};
            else if(maxi < up)
                high = mid-1;
            else
                low = mid+1;
        }
        return {-1, -1};
    }
};