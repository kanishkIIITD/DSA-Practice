class Solution {
public:
    vector<int> generateRow(int row){
        vector<int> ans;
        int temp = 1;
        ans.push_back(temp);
        for(int i = 1; i < row; i++){
            temp = temp * (row - i);
            temp = temp / i;
            ans.push_back(temp);
        }
        return ans;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 1; i <= numRows; i++){
            ans.push_back(generateRow(i));
        }
        return ans;
    }
};