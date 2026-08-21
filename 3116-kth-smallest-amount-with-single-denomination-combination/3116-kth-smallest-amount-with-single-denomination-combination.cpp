class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        vector<long long> lcms;
        vector<int> signs;
        for (int mask = 1; mask < (1 << n); mask++) {
            long long current_lcm = 1;
            int set_bits = 0;
            
            for (int i = 0; i < n; i++) {
                if ((mask >> i) & 1) {
                    current_lcm = std::lcm(current_lcm, (long long)coins[i]);
                    set_bits++;
                }
            }
            lcms.push_back(current_lcm);
            signs.push_back(set_bits % 2 == 1 ? 1 : -1);
        }
        
        long long low = 1;
        long long high = (long long)k * *min_element(coins.begin(), coins.end());
        
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long count = 0;
            
            for (int i = 0; i < lcms.size(); i++) {
                count += signs[i] * (mid / lcms[i]);
            }
            
            if (count >= k) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return low;
    }
};