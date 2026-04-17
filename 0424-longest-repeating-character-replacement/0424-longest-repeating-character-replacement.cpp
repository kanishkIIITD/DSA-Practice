class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxFreq = 0, maxi = 0, j = 0;
        vector<int> hash(26);
        for(int i = 0; i < s.size(); i++){
            hash[s[i] - 'A']++;
            maxFreq = max(maxFreq, hash[s[i] - 'A']);
            if((i - j + 1) - maxFreq > k){
                hash[s[j] - 'A']--;
                j++;
            }
            if((i - j + 1) - maxFreq <= k)
                maxi = max(maxi, i - j + 1);
        }
        return maxi;
    }
};