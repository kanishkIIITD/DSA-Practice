class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maxi = INT_MIN, mini = INT_MAX;
        for(auto n: nums){
            maxi = max(maxi, n);
            mini = min(mini, n);
        }
        return gcd(maxi, mini);
    }
};