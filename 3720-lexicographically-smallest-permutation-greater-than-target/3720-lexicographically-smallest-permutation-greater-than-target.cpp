class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> hash(26);
        for(int i = 0; i < n; i++)
            hash[s[i] - 'a']++;
        int li = -1;
        char lc = 'a';
        string ans = "";
        for(int i = 0; i < n; i++){
            char ch = target[i];
            for(int j = ch - 'a' + 1; j < 26; j++){
                if(hash[j] > 0){
                    li = i;
                    lc = j + 'a';
                    break;
                }
            }
            if(hash[ch - 'a'] > 0){
                hash[ch - 'a']--;
                ans += ch;
            }
            else{
                break;
            }
        }
        if(li != -1){
            vector<int> rem(26);
            for(int i = 0; i < n; i++)
                rem[s[i] - 'a']++;
            string f = target.substr(0, li);
            for(char c: f)
                rem[c - 'a']--;
            f += lc;
            rem[lc - 'a']--;
            for(int k = 0; k < 26; k++){
                while(rem[k] > 0){
                    rem[k]--;
                    f += k + 'a';
                }
            }
            return f;
        }
        return "";
    }
};