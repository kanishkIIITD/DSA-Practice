class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int j = 0;
        int n = cardPoints.size();
        int lsum = 0;
        while(j < k && j < n){
            lsum += cardPoints[j];
            j++;
        }
        if(k >= n)
            return lsum;
        j = k-1;
        int maxi = lsum;
        for(int i = 0; i < k; i++){
            lsum -= cardPoints[j];
            j--;
            lsum += cardPoints[n-1-i];
            maxi = max(maxi, lsum);
        }
        return maxi;
    }
};