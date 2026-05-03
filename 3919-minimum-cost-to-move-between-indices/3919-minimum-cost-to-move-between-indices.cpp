class Solution {
public:
    // int solve(vector<int>& nums, int l, int r, vector<int>& closest){
    //     int direction = l < r ? 0 : 1; // 0 -> left to right, 1 -> right to left
    //     int cost = 0;
    //     while(l != r){
    //         if(!direction && closest[l] > l || direction && closest[l] < l){
    //             cost += 1;
    //             l = closest[l];
    //         }
    //         else{
    //             if(!direction){
    //                 cost += abs(nums[l] - nums[l+1]);
    //                 l++;
    //             }
    //             else{
    //                 cost += abs(nums[l] - nums[l-1]); 
    //                 l--;
    //             }
    //         }
    //     }
    //     return cost;
    // }
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> closest;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(i == 0)
                closest.push_back(1);
            else if(i == n-1)
                closest.push_back(n-2);
            else{
                int left = abs(nums[i] - nums[i-1]);
                int right = abs(nums[i] - nums[i+1]);
                if(left <= right)
                    closest.push_back(i-1);
                else
                    closest.push_back(i+1);
            }
        }
        vector<int> preLR(n);
        vector<int> preRL(n);
        for(int i = 0; i < n-1; i++){
            int cost = closest[i] == i+1 ? 1 : abs(nums[i]- nums[i+1]);
            preLR[i+1] = preLR[i] + cost;
        }
        for(int i = n-1; i > 0; i--){
            int cost = closest[i] == i-1 ? 1 : abs(nums[i]- nums[i-1]);
            preRL[i-1] = preRL[i] + cost;
        }
        vector<int> ans;
        for(int i = 0; i < queries.size(); i++){
            int l = queries[i][0];
            int r = queries[i][1];
            if(l < r)
                ans.push_back(preLR[r] - preLR[l]);
            else if(r < l)
                ans.push_back(preRL[r] - preRL[l]);
            else
                ans.push_back(0);
        }
        return ans;
    }
};