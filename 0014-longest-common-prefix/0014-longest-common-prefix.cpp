class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        for(int i = 0; i < strs[0].size(); i++){
            char ch = strs[0][i];
            bool flag = 0;
            for(int j = 1; j < strs.size(); j++){
                if(i >= strs[j].size() || strs[j][i] != ch){
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)
                break;
            ans += ch;
        }
        return ans;
    }
};