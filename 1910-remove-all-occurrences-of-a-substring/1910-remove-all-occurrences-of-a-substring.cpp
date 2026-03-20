class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ans;
        int p = part.size();
        for(int i = 0; i < s.size(); i++){
            ans.push_back(s[i]);
            if(ans.length() > p-1 && ans.substr(ans.length()-p, p) == part)
                ans.erase(ans.length() - p);
        }
        return ans;
    }
};