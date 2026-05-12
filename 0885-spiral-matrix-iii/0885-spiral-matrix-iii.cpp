class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;
        ans.push_back({rStart, cStart});
        int steps = 1;
        int dir = 0;
        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};
        while(ans.size() < rows * cols){
            for(int i = 0; i < 2; i++){
                for(int j = 0; j < steps; j++){
                    rStart += dr[dir];
                    cStart += dc[dir];
                    if(0 <= rStart && rStart < rows && 0 <= cStart && cStart < cols)
                        ans.push_back({rStart, cStart});
                }
                dir = (dir + 1) % 4;
            }
            steps++;
        }
        return ans;
    }
};