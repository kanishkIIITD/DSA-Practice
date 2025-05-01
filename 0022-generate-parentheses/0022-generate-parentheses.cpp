class Solution {
public:
    void solve (int i, int k, string&s, vector<string>&ans, int n){
        if(i == n && k == 0){
            ans.push_back(s);
            return;
        }
        if(i+1 <= n){
            s += '(';
            solve(i+1, k+1, s, ans, n);
            s.pop_back();
        }
        if(k > 0){
            s += ')';
            solve(i, k-1, s, ans, n);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        solve(0, 0, s, ans, n);
        return ans;
    }
};