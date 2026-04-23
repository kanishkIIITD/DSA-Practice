class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> arr(n, 0);
        
        // Step 1: Map each number to its list of indices
        unordered_map<int, vector<long long>> indices;
        for (int i = 0; i < n; i++) {
            indices[nums[i]].push_back(i);
        }
        
        // Step 2 & 3: Calculate prefix sums for each unique number
        for (auto& [val, idxList] : indices) {
            int k = idxList.size();
            long long totalSum = 0;
            
            for (long long idx : idxList) {
                totalSum += idx;
            }
            
            long long leftSum = 0;
            for (int i = 0; i < k; i++) {
                long long currIdx = idxList[i];
                
                // The sum of all indices to the right of the current index
                long long rightSum = totalSum - leftSum - currIdx;
                
                // Formula for elements on the left
                long long leftDist = ((long long)i * currIdx) - leftSum;
                
                // Formula for elements on the right
                long long rightDist = rightSum - ((long long)(k - 1 - i) * currIdx);
                
                arr[currIdx] = leftDist + rightDist;
                
                // Update leftSum for the next iteration
                leftSum += currIdx;
            }
        }
        
        return arr;
    }
};