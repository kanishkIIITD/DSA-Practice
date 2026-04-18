class Solution {
public:
    int numberOfSubstrings(string s) {
        int hash[3] = {0};
        int j = 0, count = 0;
        for(int i = 0; i < s.size(); i++){
            hash[s[i] - 'a']++;
            while(hash[0] > 0 && hash[1] > 0 && hash[2] > 0){
                count += (s.size() - i);
                hash[s[j] - 'a']--;
                j++;
            }
        }
        return count;
    }
};