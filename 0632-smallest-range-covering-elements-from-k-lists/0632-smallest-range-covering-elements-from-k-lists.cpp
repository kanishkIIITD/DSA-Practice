class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int currentMax = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            pq.push({nums[i][0], {i, 0}});
            currentMax = max(currentMax, nums[i][0]);
        }
        int bestStart = pq.top().first;
        int bestEnd = currentMax;
        while(!pq.empty()){
            int currentMin = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if(currentMax - currentMin < bestEnd - bestStart){
                bestStart = currentMin;
                bestEnd = currentMax;
            }
            if(col + 1 < nums[row].size()){
                pq.push({nums[row][col+1], {row, col+1}});
                currentMax = max(currentMax, nums[row][col+1]);
            }
            else
                break;
        }
        return {bestStart, bestEnd};
    }
};