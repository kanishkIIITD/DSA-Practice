class Solution {
public:
    void solveRE(vector<int>&prices, int i, int& minPrice, int& maxProfit){
        // base case
        if(i >= prices.size())
            return;

        // 1 case solution  
        if(prices[i] < minPrice)
            minPrice = prices[i];
        if(prices[i] - minPrice > maxProfit)
            maxProfit = prices[i] - minPrice;

        // RE
        solveRE(prices, i+1, minPrice, maxProfit);

    }
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = INT_MIN;
        solveRE(prices, 0, minPrice, maxProfit);
        return maxProfit;
    }
};