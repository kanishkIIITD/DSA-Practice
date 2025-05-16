class Solution {
public:
    int numberOfSubstrings(string s) {
        int hash[3] = {-1, -1, -1};
        int count = 0;
        for(int i = 0; i < s.size(); i++){
            hash[s[i] - 'a'] = i;
            if(hash[0] != -1 && hash[1] != -1 && hash[2] != -1){
                int minIndex = min(hash[0], min(hash[1], hash[2]));
                count += minIndex + 1;
            }
        }
        return count;
    }
};