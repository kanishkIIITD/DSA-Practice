class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        if(s[n-1] == '1')
            return false;
        vector<int> dp(n);
        dp[0] = 1;
        int count = 0;
        for(int i = 1; i < n; i++){
            if(i >= minJump && dp[i - minJump])
                count++;
            if(i > maxJump && dp[i - maxJump - 1])
                count--;
            if(count > 0 && s[i] == '0')
                dp[i] = 1;
        }
        return dp[n-1];
    }
};