class Solution {
public:
    bool isPossible(string& a, string& b){
        if(a.size() != b.size() + 1) return false;
        
        int i = 0; 
        int j = 0; 
        
        while(i < a.size()) {
            if(j < b.size() && a[i] == b[j]) {
                i++;
                j++;
            } else {
                i++;
            }
        }

        return j == b.size();
    }
    int solve(int i, int prev, vector<string>& words, vector<vector<int>> &dp){
        if(i == words.size())
            return 0;
        if(dp[i][prev] != -1)
            return dp[i][prev];
        int notpick = solve(i+1, prev, words, dp);
        int pick = 0;
        if(prev == 0 || isPossible(words[i], words[prev-1]))
            pick = 1 + solve(i+1, i+1, words, dp);
        return dp[i][prev] = max(pick, notpick);
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [](const string& s1, const string& s2){
            return s1.size() < s2.size();
        });
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, 0, words, dp);
    }
};