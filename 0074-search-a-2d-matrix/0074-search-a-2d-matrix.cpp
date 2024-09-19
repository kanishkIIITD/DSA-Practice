class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int s = 0;
        int e = rows*cols-1;
        while(s <= e){
            int m = s + (e-s)/2;
            int rowIndex = m/cols;
            int colIndex = m%cols;

            if(matrix[rowIndex][colIndex] == target)
                return true;
            else if (matrix[rowIndex][colIndex] > target)
                e = m-1;
            else    
                s = m+1;
        }
        return false;
    }
};