class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> mp(128, 0);
        for(char &ch: t)
            mp[ch]++;
        int j = 0, count = 0, len = INT_MAX;
        int start_idx = 0;
        for(int i = 0; i < s.size(); i++){
            if(mp[s[i]] > 0)
                count++;
            mp[s[i]]--;
            while(count == t.size()){
                if(i - j + 1 < len){
                    len = i - j + 1;
                    start_idx = j;
                }
                mp[s[j]]++;
                if(mp[s[j]] > 0)
                    count--;
                j++;
            }
        }
        return len == INT_MAX ? "" : s.substr(start_idx, len);
    }
};