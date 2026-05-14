class Solution {
public:
    bool isGood(vector<int>& nums) {
        int maxi = INT_MIN;
        for(auto& num: nums)
            maxi = max(maxi, num);
        int n = nums.size();
        if(n != maxi + 1)
            return false;
        vector<int> freq(n);
        for(auto& num: nums){
            freq[num]++;
        }
        for(int i = 1; i < n; i++){
            if(i == n-1 && freq[i] != 2)
                return false;
            else if(i != n-1 && freq[i] != 1)
                return false;
        }
        return true;
    }
};