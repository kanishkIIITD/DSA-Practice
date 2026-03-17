class Solution {
public:
    bool isPossible(vector<int>& weights, int days, int capacity){
        int sum = 0, count = 0;
        for(int i = 0; i < weights.size(); i++){
            sum += weights[i];
            if(sum > capacity){
                count++;
                sum = weights[i];
            }
        }
        count++;
        return count <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = 0;
        for(int i = 0; i < weights.size(); i++)
            high += weights[i];
        int mid;
        while(low <= high){
            mid = low + (high - low) / 2;
            if(isPossible(weights, days, mid))
                high = mid-1;
            else
                low = mid+1;
        }
        return low;
    }
};