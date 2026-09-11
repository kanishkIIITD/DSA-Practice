class Solution {
public:
    void solve(int len, int num, vector<int>& digits, unordered_set<int>& st, vector<int>& vis){
        if(len == 3){
            if(num >= 100 && num % 2 == 0)
                st.insert(num);
            return;
        }
        for(int i = 0; i < digits.size(); i++){
            if(!vis[i]){
                vis[i] = 1;
                solve(len+1, num*10 + digits[i], digits, st, vis);
                vis[i] = 0;
            }
        }
    }
    int totalNumbers(vector<int>& digits) {
        unordered_set<int> st;
        vector<int> vis(digits.size());
        solve(0, 0, digits, st, vis);
        return st.size();
    }
};