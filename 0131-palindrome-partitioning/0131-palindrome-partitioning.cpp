class Solution {
public:
    bool isPalindrome(string s){
        int l = 0, h = s.size()-1;
        while(l <= h){
            if(s[l] != s[h])
                return false;
            l++;
            h--;
        }
        return true;
    }
    void solve(string s, int index, vector<string>& temp, vector<vector<string>>& ans){
        if(index == s.size()){
            ans.push_back(temp);
            return;
        }
        for(int i = index; i < s.size(); i++){
            string str = s.substr(index, i-index+1);
            if(isPalindrome(str)){
                temp.push_back(str);
                solve(s, i+1, temp, ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(s, 0, temp, ans);
        return ans;
    }
};