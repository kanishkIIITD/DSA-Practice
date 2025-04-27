class Solution {
public:
    vector<int> concatenatedDivisibility(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n == 0) return {};

        vector<int> pow10(n), num_mod(n);
        for (int i = 0; i < n; ++i) {
            string s = to_string(nums[i]);
            int len = s.length();
            int p = 1;
            for (int j = 0; j < len; ++j) {
                p = (p * 10) % k;
            }
            pow10[i] = p;
            int mod = 0;
            for (char c : s) {
                mod = (mod * 10 + (c - '0')) % k;
            }
            num_mod[i] = (mod % k + k) % k;
        }

        unordered_map<int, unordered_map<int, vector<int>>> memo;

        function<vector<int>(int, int)> dp = [&](int mask, int current_mod) -> vector<int> {
            if (mask == (1 << n) - 1) {
                if (current_mod == 0) return {};
                else return {-1}; // Use -1 as invalid marker
            }

            if (memo.count(mask) && memo[mask].count(current_mod)) {
                return memo[mask][current_mod];
            }

            vector<int> best;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) continue;
                if (i > 0 && nums[i] == nums[i-1] && !(mask & (1 << (i-1)))) continue;

                int new_mod = (current_mod * pow10[i] + num_mod[i]) % k;
                new_mod = (new_mod + k) % k;

                vector<int> next = dp(mask | (1 << i), new_mod);
                if (!next.empty() || (mask | (1 << i)) == (1 << n) - 1) {
                    vector<int> candidate;
                    if (next.empty() && (mask | (1 << i)) == (1 << n) - 1) {
                        if (new_mod == 0) {
                            candidate.push_back(nums[i]);
                        } else {
                            continue;
                        }
                    } else if (next.size() == 0 || next[0] == -1) {
                        continue;
                    } else {
                        candidate.push_back(nums[i]);
                        candidate.insert(candidate.end(), next.begin(), next.end());
                    }

                    if (candidate.empty()) continue;
                    if (best.empty() || candidate < best) {
                        best = candidate;
                    }
                }
            }

            if (best.empty()) {
                memo[mask][current_mod] = {-1};
            } else {
                memo[mask][current_mod] = best;
            }
            return memo[mask][current_mod];
        };

        vector<int> result = dp(0, 0);
        if (result.empty() || result[0] == -1) return {};
        return result;
    }
};