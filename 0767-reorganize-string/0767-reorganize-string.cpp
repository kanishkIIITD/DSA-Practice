class Solution {
public:
    string reorganizeString(string s) {
        int hash[26] = {0};
        int max_char_freq = 0;
        char max_char;
        for(int i = 0; i < s.size(); i++){
            hash[s[i] - 'a']++;
            if(hash[s[i] - 'a'] > max_char_freq){
                max_char_freq = hash[s[i] - 'a'];
                max_char = s[i];
            }
        }

        int i = 0;
        while(max_char_freq > 0 && i < s.size()){
            s[i] = max_char;
            max_char_freq--;
            i += 2;
        }

        if(max_char_freq != 0)
            return "";
        
        hash[max_char - 'a'] = 0;
        
        for(int j = 0; j < 26; j++){
            while(hash[j] > 0){
                i = i >= s.size() ? 1 : i;
                s[i] = j + 'a';
                hash[j]--;
                i += 2;
            }
        }
        return s;
    }
};