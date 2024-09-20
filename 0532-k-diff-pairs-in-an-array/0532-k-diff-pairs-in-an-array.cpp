class Solution {
public:
    int binarySearch(vector<int>&nums, int start, int end, int target){
        int s = start;
        int e = end;
        while(s <= e){
            int m = s + (e-s)/2;
            if(nums[m] == target)
                return m;
            else if(nums[m] > target)
                e = m-1;
            else 
                s = m+1;
        }
        return -1;
    }
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        if(nums.size() == 1)
            return 0;

        // map<pair<int, int>, int> M;
        // int i = 0;
        // int j = 1;
        // int ans = 0;
        // while(j < nums.size()){
        //     int diff = nums[j] - nums[i];
        //     if(diff == k && i != j && M[{nums[i], nums[j]}] < 1){
        //         M[{nums[i], nums[j]}] ++;
        //         ans++;
        //         i++;
        //         j++;
        //     }
        //     else if(diff > k){
        //         i++;
        //     }
        //     else{
        //         j++;
        //     }
        // }
        // return ans;

        // Solution 2
        set<pair<int, int>> ans;
        for(int i = 0; i < nums.size()-1; i++){
            int target = k + nums[i];
            int index = binarySearch(nums, i+1, nums.size()-1, target);
            if(index != -1)
                ans.insert(pair(nums[i], nums[index]));
        }
        return ans.size();
    }
};