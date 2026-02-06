class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0 = 1;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    j == 0 ? col0 = 0 : matrix[0][j] = 0;
                }
            }
        }

        for(int i = n-1; i > 0; i--){
            for(int j = m-1; j > 0; j--){
                if(!matrix[i][0] || !matrix[0][j]){
                    matrix[i][j] = 0;
                }
            }
        }
        for(int j = m-1; j > 0; j--){
            if(!matrix[0][0])
                matrix[0][j] = 0;
        }
        for(int i = n-1; i >= 0; i--){
            if(!col0)
                matrix[i][0] = 0;

        }
    }
};