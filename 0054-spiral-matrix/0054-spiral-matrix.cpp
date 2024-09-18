class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int totalElements = m * n;
        vector<int> ans;

        int startRow = 0;
        int startCol = n - 1;
        int endRow = m - 1;
        int endCol = 0;
        int count = 0;

        while (count < totalElements) {

            for (int j = endCol; j <= startCol; j++) {
                if (matrix[startRow][j] <= 100) {
                    ans.push_back(matrix[startRow][j]);
                    count++;
                    matrix[startRow][j] = 101;
                }
            }

            for (int i = startRow; i <= endRow; i++) {
                if (matrix[i][startCol] <= 100) {
                    ans.push_back(matrix[i][startCol]);
                    count++;
                    matrix[i][startCol] = 101;
                }
            }

            for (int j = startCol; j >= endCol; j--) {
                if (matrix[endRow][j] <= 100) {
                    ans.push_back(matrix[endRow][j]);
                    count++;
                    matrix[endRow][j] = 101;
                }
            }

            for (int i = endRow; i >= startRow; i--) {
                if (matrix[i][endCol] <= 100) {
                    ans.push_back(matrix[i][endCol]);
                    count++;
                    matrix[i][endCol] = 101;
                }
            }
            startRow++;
            startCol--;
            endRow--;
            endCol++;
        }
        return ans;
    }
};