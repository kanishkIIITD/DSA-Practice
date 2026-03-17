class Solution {
public:
    bool isPossible(vector<int>& bloomDay, int m, int k, int day){
        int count = 0, ans = 0;
        for(int i = 0; i < bloomDay.size(); i++){
            if(bloomDay[i] > day){
                ans += count / k;
                count = 0;
            }
            else
                count++;
        }
        ans += count / k;
        return ans >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m * k > bloomDay.size())
            return -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int mid;
        while(low <= high){
            mid = low + (high - low) / 2;
            if(isPossible(bloomDay, m, k, mid))
                high = mid-1;
            else
                low = mid+1;
        }
        return low;
    }
};