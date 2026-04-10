class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int mini = INT_MAX;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(nums[j] != nums[i])
                    continue;
                for(int k = j+1; k < n; k++){
                    if(nums[k] != nums[j])
                        continue;
                    mini = min(mini, abs(i-j) + abs(j-k) + abs(k-i));
                }
            }
        }  
        return mini == INT_MAX ? -1 : mini;      
    }
};