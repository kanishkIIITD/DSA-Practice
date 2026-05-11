class Solution {
public:
    void solve(int num, vector<int>& ans){
        int len = 0;
        while(num){
            int digit = num % 10;
            ans.push_back(digit);
            len++;
            num = num / 10;
        }
        int i = ans.size() - len;
        int j = ans.size()-1;
        while(i < j){
            swap(ans[i], ans[j]);
            i++;
            j--;
        }
    }
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(auto& num: nums){
            solve(num, ans);
        }
        return ans;
    }
};