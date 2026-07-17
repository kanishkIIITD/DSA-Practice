class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int max_val = 0;
        for (int num : nums) {
            max_val = max(max_val, num);
        }
        
        // Step 1: Count frequencies of each number
        vector<long long> count(max_val + 1, 0);
        for (int num : nums) {
            count[num]++;
        }
        
        vector<long long> exact(max_val + 1, 0);
        
        // Step 2 & 3: Sieve backwards to calculate exact GCD pair counts
        for (int i = max_val; i >= 1; --i) {
            long long multiples_count = 0;
            // Count how many numbers are multiples of i
            for (int j = i; j <= max_val; j += i) {
                multiples_count += count[j];
            }
            
            // Total pairs where both elements are multiples of i
            long long pairs = multiples_count * (multiples_count - 1) / 2;
            
            // Subtract pairs where the GCD is a strict multiple of i
            for (int j = 2 * i; j <= max_val; j += i) {
                pairs -= exact[j];
            }
            
            exact[i] = pairs;
        }
        
        // Step 4: Build prefix sums
        vector<long long> pref(max_val + 1, 0);
        for (int i = 1; i <= max_val; ++i) {
            pref[i] = pref[i - 1] + exact[i];
        }
        
        // Step 5: Answer queries
        vector<int> ans;
        ans.reserve(queries.size());
        
        for (long long q : queries) {
            // Find the first index where the prefix sum is strictly greater than q.
            // Using std::upper_bound is a clean way to do this binary search.
            auto it = upper_bound(pref.begin() + 1, pref.end(), q);
            int gcd_val = distance(pref.begin(), it);
            ans.push_back(gcd_val);
        }
        
        return ans;
    }
};