class Solution {
public:
    bool isPalindrome(string&s){
        int i = 0; 
        int j = s.size()-1;
        while(i < j){
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(string&s, int i, vector<string>&ds, vector<vector<string>>& ans){
        if(i >= s.size()){
            ans.push_back(ds);
            return;
        }
        for(int idx = i; idx < s.size(); idx++){
            string temp = s.substr(i, idx - i + 1);
            if(isPalindrome(temp)){
                ds.push_back(temp);
                solve(s, idx+1, ds, ans);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        solve(s, 0, ds, ans);
        return ans;
    }
};