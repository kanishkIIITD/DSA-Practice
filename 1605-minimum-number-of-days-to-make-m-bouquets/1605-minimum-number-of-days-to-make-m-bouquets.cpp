class Solution {
public:
    int maxElement(vector<int>&bloomday){
        int maxi = INT_MIN;
        for(int i = 0; i < bloomday.size(); i++)
            maxi = max(maxi, bloomday[i]);
        return maxi;
    }
    int minElement(vector<int>&bloomday){
        int mini = INT_MIN;
        for(int i = 0; i < bloomday.size(); i++)
            mini = min(mini, bloomday[i]);
        return mini;
    }

    bool isBouquetsMakable(vector<int>&bloomday, long long mid, int m, int k){
        int finalCounter = 0; // No. of possible bouquets
        int counter = 0; // To check number of adjacent flowers
        for(int i = 0; i < bloomday.size(); i++){
            if(bloomday[i] - mid <= 0)
                counter++;
            else{
                finalCounter += counter/k;
                counter = 0;
            } 
        }
        finalCounter += counter/k;
        return finalCounter >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        // edge case
        if((long long)m*k > bloomDay.size())
            return -1;
        long long low = minElement(bloomDay);
        long long high = maxElement(bloomDay);
        while(low <= high){
            long long mid = low + (high - low)/2;
            if(isBouquetsMakable(bloomDay, mid, m, k))
                high = mid-1;
            else
                low = mid+1;
        }
        return low;
    }
};