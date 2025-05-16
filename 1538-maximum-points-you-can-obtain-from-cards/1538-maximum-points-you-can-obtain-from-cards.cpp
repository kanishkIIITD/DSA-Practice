class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum = 0;
        for(int i = 0; i < k; i++)
            lsum += cardPoints[i];
        int rsum = 0;
        int maxSum = lsum;
        int rindex = cardPoints.size()-1;
        for(int i = k-1; i >= 0; i--){
            lsum -= cardPoints[i];
            rsum += cardPoints[rindex];
            maxSum = max(maxSum, lsum+rsum);
            rindex--;
        }
        return maxSum;
    }
};