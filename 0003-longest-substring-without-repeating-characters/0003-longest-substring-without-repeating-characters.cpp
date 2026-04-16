class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256);
        int j = 0;
        int maxi = 0, len = 0;
        for(int i = 0; i < s.size(); i++){
            len++;
            hash[s[i]]++;
            while(hash[s[i]] != 1){
                hash[s[j]]--;
                j++;
                len--;
            }
            maxi = max(maxi, len);
        }
        return maxi;
    }
};