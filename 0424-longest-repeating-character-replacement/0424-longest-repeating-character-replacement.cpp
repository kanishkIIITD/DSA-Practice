class Solution {
public:
    int characterReplacement(string s, int k) {
        int hash[26] = {0};
        int l = 0;
        int maxLen = 0;
        for(int r = 0; r < s.size(); r++){
            hash[s[r] - 'A']++;
            int maxEle = *max_element(hash, hash+26);
            int len = r - l + 1;
            while(len - maxEle > k){
                hash[s[l] - 'A']--;
                l++;
                maxEle = *max_element(hash, hash+26);
                len = r - l + 1;
            }
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};