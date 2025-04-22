class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        // int n = nums.size();
        // set<vector<int>> unq;
        // for(int i = 0; i < n; i++){
        //     set<int> st;
        //     for(int j = i+1; j < n; j++){
        //         int ele = -(nums[i] + nums[j]);
        //         if(st.find(ele) != st.end()){
        //             vector<int> temp = {nums[i], nums[j], ele};
        //             sort(temp.begin(), temp.end());
        //             unq.insert(temp);
        //         }
        //         else
        //             st.insert(nums[j]);
        //     }
        // }
        // vector<vector<int>> ans(unq.begin(), unq.end());
        // return ans;

        // Optimized solution
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            int j = i+1;
            int k = n-1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0){
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while(j < k && nums[j] == nums[j-1]) j++;
                    while(j < k && nums[k] == nums[k+1]) k--;
                }
                else if(sum < 0)
                    j++;
                else 
                    k--;
            }
        }
        return ans;
    }
};