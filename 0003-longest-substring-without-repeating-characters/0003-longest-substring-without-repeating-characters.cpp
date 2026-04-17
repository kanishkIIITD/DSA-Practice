class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256, -1);
        int j = 0;
        int maxi = 0;
        for(int i = 0; i < s.size(); i++){
            if(hash[s[i]] != -1){
                if(hash[s[i]] >= j)
                    j = hash[s[i]] + 1;
            }
            maxi = max(maxi, i - j + 1);
            hash[s[i]] = i;
        }
        return maxi;
    }
};