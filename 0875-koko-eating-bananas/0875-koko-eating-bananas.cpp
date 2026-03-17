class Solution {
public:
    long long timeToEat(vector<int>& piles, int k){
        long long time = 0;
        for(int i = 0; i < piles.size(); i++){
            time += (piles[i] + k - 1LL) / k;
        }
        return time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        // int low = *min_element(piles.begin(), piles.end());
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int mid;
        while(low <= high){
            mid = low + (high - low) / 2;
            long long time = timeToEat(piles, mid);
            if(time <= h)
                high = mid-1;
            else
                low = mid+1;
        }
        return low;
    }
};