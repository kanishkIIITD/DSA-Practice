class Solution {
public:
    int getMaxInCol(vector<vector<int>>& mat, int col){
        int index = -1;
        int maxi = INT_MIN;
        int nRows = mat.size();
        for(int i = 0; i < nRows; i++){
            if(mat[i][col] > maxi){
                maxi = mat[i][col];
                index = i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int nRows = mat.size();
        int nCols = mat[0].size();
        int low = 0;
        int high = nCols-1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            int maxRow = getMaxInCol(mat, mid);
            int left = mid - 1 >= 0 ? mat[maxRow][mid-1] : -1;
            int right = mid + 1 < nCols ? mat[maxRow][mid+1] : -1;
            if(left < mat[maxRow][mid] && mat[maxRow][mid] > right)
                return {maxRow, mid};
            else if(left > mat[maxRow][mid])
                high = mid-1;
            else 
                low = mid+1;
        }
        return {-1, -1};
    }
};