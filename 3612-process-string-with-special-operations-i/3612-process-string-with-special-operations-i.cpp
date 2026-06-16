class Solution {
public:
    string processStr(string s) {
        string ans = "";
        int n = s.size();
        for(int i = 0; i < n; i++){
            if('a' <= s[i] && s[i] <= 'z')
                ans += s[i];
            else if(s[i] == '*'){
                if(ans.size() > 0)
                    ans.pop_back();
            }
            else if(s[i] == '#'){
                string cpy = "";
                for(auto ch: ans)
                    cpy += ch;
                ans += cpy;
            }
            else if(s[i] == '%'){
                int l = 0, r = ans.size()-1;
                while(l < r){
                    swap(ans[l], ans[r]);
                    l++;
                    r--;
                }
            }
        }
        return ans;
    }
};