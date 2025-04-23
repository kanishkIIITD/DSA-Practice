class Solution {
public:
    long long getTime(vector<int>&piles, int n){
        long long time = 0;
        for(int i = 0; i < piles.size(); i++){
            time += ceil((double)piles[i] / (double)n);
        }
        return time;
    }
    int getMin(vector<int>&piles){
        int mini = INT_MAX;
        for(int i = 0; i < piles.size(); i++)
            mini = min(mini, piles[i]);
        return mini;
    }
    int getMax(vector<int>&piles){
        int maxi = INT_MIN;
        for(int i = 0; i < piles.size(); i++)
            maxi = max(maxi, piles[i]);
        return maxi;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = getMax(piles);
        while(low <= high){
            int mid = (low + high) / 2;
            long long time = getTime(piles, mid);
            if(time <= h)
                high = mid-1;
            else
                low = mid+1;
        }
        return low;
    }
};