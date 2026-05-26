class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> up(26);
        vector<int> lo(26);
        for(auto& ch: word){
            if(isupper(ch))
                up[ch-'A']++;
            else if(islower(ch))
                lo[ch-'a']++;
        }
        int count = 0;
        for(int i = 0; i < 26; i++){
            if(up[i] > 0 && lo[i] > 0)
                count++;
        }
        return count;
    }
};