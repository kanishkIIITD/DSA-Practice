class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxEle = *max_element(nums.begin(), nums.end());
        int i = 0;
        int j = 0;
        long long ans = 0;
        long long count = 0;
        while(j < nums.size() && i <= j){
            if(nums[j] == maxEle)
                count++;
            j++;
            while(count >= k){
                if(nums[i] == maxEle)
                    count--;
                i++;
            }
            ans += i;
        }
        return ans;
    }
};