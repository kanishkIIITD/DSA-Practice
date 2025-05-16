class Solution {
public:
    // int getNoOfChar(int hash[]){
    //     int ans = 0;
    //     for(int i = 0; i < 256; i++){
    //         if(hash[i] > 0)
    //             ans++;
    //     }
    //     return ans;
    // }
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        // int hash[256] = {0};
        unordered_map<char, int> mp;
        int maxLen = 0;
        int l = 0;
        for(int r = 0; r < s.size(); r++){
            // hash[s[r]]++;
            mp[s[r]]++;
            // if(getNoOfChar(hash) > k)
            while(mp.size() > k) {
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