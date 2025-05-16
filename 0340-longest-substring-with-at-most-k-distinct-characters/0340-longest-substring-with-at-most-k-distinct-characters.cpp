class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> mp;
        int maxLen = 0;
        int l = 0;
        for(int r = 0; r < s.size(); r++){
            mp[s[r]]++;
            if(mp.size() > k) {
                mp[s[l]]--;
                if(mp[s[l]] == 0)
                    mp.erase(s[l]);
                l++;
            }
            maxLen = max(maxLen, r-l+1);
        }
        return maxLen;
    }
};