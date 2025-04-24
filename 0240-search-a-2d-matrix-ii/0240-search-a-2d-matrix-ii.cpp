class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int nRows = matrix.size();
        int nCols = matrix[0].size();
        int i = 0;
        int j = nCols - 1;
        while(i < nRows && j >= 0){
            if(matrix[i][j] == target)
                return true;
            else if(matrix[i][j] < target)
                i++;
            else
                j--;
        }
        return false;
    }
};