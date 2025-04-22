class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Brute Force
        // vector<int> ans;
        // for(int i = 0; i < nums.size()-1; i++){
        //     int newTarget = target - nums[i];
        //     for(int j = i+1; j < nums.size(); j++){
        //         if(newTarget == nums[j]){
        //             ans.push_back(i);
        //             ans.push_back(j);
        //         }
        //     }
        // }
        // return ans;

        // Better
        vector<int> ans;
        map<int, int> mp;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int ele = nums[i];
            int req = target - ele;
            if(mp.find(req) != mp.end()){
                ans = {mp[req], i};
                return ans;
            }   
            mp[ele] = i;
        }
        return ans;
    }
};