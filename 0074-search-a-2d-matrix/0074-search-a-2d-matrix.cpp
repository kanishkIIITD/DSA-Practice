class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0, high = m*n-1, mid;
        while(low <= high){
            mid = low + (high - low) / 2;
            int midRow = mid / n;
            int midCol = mid % n;
            int midEle = matrix[midRow][midCol];
            if(midEle == target)
                return true;
            else if(midEle > target)
                high = mid-1;
            else
                low = mid+1;
        }
        return false;
    }
};