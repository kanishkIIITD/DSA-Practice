class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        if(nums.size() == 1)
            return 0;

        map<pair<int, int>, int> M;
        int i = 0;
        int j = 1;
        int ans = 0;
        while(j < nums.size()){
            int diff = nums[j] - nums[i];
            if(diff == k && i != j && M[{nums[i], nums[j]}] < 1){
                M[{nums[i], nums[j]}] ++;
                ans++;
                i++;
                j++;
            }
            else if(diff > k){
                i++;
            }
            else{
                j++;
            }
        }
        return ans;
    }
};