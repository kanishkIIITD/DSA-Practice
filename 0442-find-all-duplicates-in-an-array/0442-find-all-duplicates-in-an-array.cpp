class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // Brute Force
        // int n = nums.size();
        // sort(nums.begin(), nums.end());
        // vector<int> ans;
        // int i = 0;
        // while(i < n-1){
        //     if(nums[i] == nums[i+1]){
        //         ans.push_back(nums[i]);
        //         i+=2;
        //     }
        //     else
        //         i++;
        // }
        // return ans;

        // Better
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> mp; //{element, count}
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }
        for(auto it: mp){
            if(it.second == 2)
                ans.push_back(it.first);
        }
        return ans;
    }
};