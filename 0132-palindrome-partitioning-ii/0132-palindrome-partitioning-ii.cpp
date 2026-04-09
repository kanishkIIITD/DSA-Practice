class Solution {
public:
    bool isPalindrome(string& s){
        int i = 0, j = s.size()-1;
        while(i < j){
            if(s[i++] != s[j--])
                return false;
        }
        return true;
    }
    int solve(int i, string& s, vector<int> &dp){
        if(i == s.size())
            return -1;
        if(dp[i] != -1)
            return dp[i];
        string temp = "";
        int ans = INT_MAX;
        for(int j = i; j < s.size(); j++){
            temp += s[j];
            if(isPalindrome(temp)){
                int cuts = 1 + solve(j+1, s, dp);
                ans = min(cuts, ans);
            }
        }
        return dp[i] = ans;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1, -1);
        return solve(0, s, dp);
    }
};