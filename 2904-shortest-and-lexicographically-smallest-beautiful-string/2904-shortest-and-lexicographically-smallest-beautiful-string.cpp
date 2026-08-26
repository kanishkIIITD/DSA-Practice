class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int ind = -1, len = INT_MAX;
        int l = 0, count = 0;
        while(l < s.size() && s[l] == '0')
            l++;
        for(int r = l; r < s.size(); r++){
            if(s[r] == '1')
                count++;
            if(count < k)
                continue;
            else{
                if(r - l + 1 < len){
                    len = r - l + 1;
                    ind = l;
                }
                else if (r - l + 1 == len) {
                    string currentStr = s.substr(l, len);
                    string previousStr = s.substr(ind, len);
                    if (currentStr < previousStr) {
                        ind = l;
                    }
                }
                if(s[l] == '1')
                    count--;
                l++;
                while(l < s.size() && s[l] == '0')
                    l++;
            }
        }
        if(ind == -1)
            return "";
        return s.substr(ind, len);
    }
};