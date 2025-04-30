class Solution {
public:
    int getDigits(int n){
        int digits = 0;
        while(n != 0){
            n = n/10;
            digits++;
        }
        return digits;
    }
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(auto it: nums){
            int digits = getDigits(it);
            if(digits % 2 == 0)
                ans++;
        }
        return ans;
    }
};