class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        long long total_original_profit = 0;
        int n = prices.size();
        for(int i = 0; i < n; i++)
            total_original_profit += prices[i] * strategy[i];
        vector<long long> pref_orig(n);
        vector<long long> pref_prices(n);
        pref_orig[0] = prices[0] * strategy[0];
        pref_prices[0] = prices[0];
        for(int i = 1; i < n; i++){
            pref_orig[i] = pref_orig[i-1] + prices[i] * strategy[i];
            pref_prices[i] = pref_prices[i-1] + prices[i];
        }
        long long delta = 0;
        for(int i = 0; i < n - k + 1; i++){
            long long old_window_profit = pref_orig[i + k - 1] - (i > 0 ? pref_orig[i - 1] : 0);
            long long new_window_profit = pref_prices[i + k - 1] - (i + k/2 > 0 ? pref_prices[i + k/2 - 1] : 0);
            delta = max(delta, new_window_profit - old_window_profit);
        }
        return total_original_profit + delta;
    }
};