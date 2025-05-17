class Solution {
public:
    string minWindow(string s, string t) {
        int hash[256] = {0};
        for(int i = 0; i < t.size(); i++)
            hash[t[i]]++;
        int minLen = INT_MAX;
        int sIndex = -1;
        int l = 0;
        int count = 0;
        for(int r = 0; r < s.size(); r++){
            if(hash[s[r]] > 0)
                count++;
            hash[s[r]]--;
            while(count == t.size()){
                if(r-l+1 < minLen){
                    minLen = r-l+1;
                    sIndex = l;
                }
                hash[s[l]]++;
                if(hash[s[l]] > 0)
                    count--;
                l++;
            }
        }
        if(sIndex == -1)
            return "";
        return s.substr(sIndex, minLen);
    }
};