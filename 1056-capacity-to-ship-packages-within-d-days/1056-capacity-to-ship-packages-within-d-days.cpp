class Solution {
public:
    int getSum(vector<int>&weights){
        int sum = 0;
        for(int i = 0; i < weights.size(); i++)
            sum += weights[i];
        return sum;
    }

    bool isTrue(vector<int>&weights, int mid, int days){
        int count = 0;
        int sum = 0;
        int n = weights.size();
        for(int i = 0; i < n; i++){
            sum += weights[i];
            if(sum <= mid)
                continue;
            else{
                count++;
                sum = weights[i];
            }
        }
        if(sum <= mid)
            count++;
        if(count <= days)
            return true;
        else
            return false;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = getSum(weights);
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(isTrue(weights, mid, days))
                high = mid-1;
            else
                low = mid+1;
        }
        return low;
    }
};