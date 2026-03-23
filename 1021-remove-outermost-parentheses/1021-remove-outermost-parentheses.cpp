class Solution {
public:
    string removeOuterParentheses(string s) {
        int count = 0, len = 0;
        string ans = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(')
                count++;
            if(s[i] == ')')
                count--;
            len++;
            if(count == 0){
                ans += s.substr(i - len + 2, len - 2);
                len = 0;
            }
        }
        return ans;
    }
};