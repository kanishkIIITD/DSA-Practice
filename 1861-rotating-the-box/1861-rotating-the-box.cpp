class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size(), n = boxGrid[0].size();
        for(int i = 0; i < m; i++){
            int e = n-1;
            for(int j = n-1; j >= 0; j--){
                if(boxGrid[i][j] == '*')
                    e = j-1;
                else if(boxGrid[i][j] == '#'){
                    swap(boxGrid[i][j], boxGrid[i][e]);
                    e--;
                }
            }
        }
        vector<vector<char>> rotatedBox(n, vector<char>(m));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                rotatedBox[j][m - i - 1] = boxGrid[i][j];
            }
        }
        return rotatedBox;
    }
};