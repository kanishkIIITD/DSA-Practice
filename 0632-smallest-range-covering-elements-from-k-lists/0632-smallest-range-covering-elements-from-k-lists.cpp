class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        int maxi = INT_MIN, mini = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i].size() > 0){
                pq.push({nums[i][0], i, 0});
                maxi = max(maxi, nums[i][0]);
                mini = min(mini, nums[i][0]);
            }
        }
        int ansStart = mini, ansEnd = maxi;
        while(!pq.empty()){
            auto [ele, i, j] = pq.top();
            pq.pop();
            mini = ele;
            if(maxi - mini < ansEnd - ansStart){
                ansStart = mini;
                ansEnd = maxi;
            }
            if(j+1 < nums[i].size()){
                pq.push({nums[i][j+1], i, j+1});
                maxi = max(maxi, nums[i][j+1]);
            }
            else
                break;
        }
        return {ansStart, ansEnd};
    }
};