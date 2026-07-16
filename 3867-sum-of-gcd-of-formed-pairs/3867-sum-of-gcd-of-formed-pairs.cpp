class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int maxi = INT_MIN;
        vector<int> prefixGcd;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            maxi = max(maxi, nums[i]);
            int g = gcd(maxi, nums[i]);
            prefixGcd.push_back(g);
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        int l = 0, r = prefixGcd.size()-1;
        long long sum = 0;
        while(l < r){
            int g = gcd(prefixGcd[l], prefixGcd[r]);
            sum += g;
            l++;
            r--;
        }
        return sum;
    }
};