class Solution {
public:
    string reorganizeString(string s) {
        int hash[26] = {0};
        for(int i = 0; i < s.length(); i++){
            hash[s[i] - 'a']++;
        }

        int most_freq = INT_MIN;
        char most_freq_char;
        for(int i = 0; i < 26; i++){
            if(hash[i] > most_freq){
                most_freq = hash[i];
                most_freq_char = i + 'a';
            }
        }

        int index = 0;
        while(most_freq > 0 && index < s.length()){
            s[index] = most_freq_char;
            most_freq--;
            index += 2;
        }

        if(most_freq != 0)
            return "";
        
        hash[most_freq_char - 'a'] = 0;
        for(int i = 0; i < 26; i++){
            while(hash[i] > 0){
                index = index >= s.length() ? 1 : index;
                s[index] = i + 'a';
                hash[i]--;
                index += 2;
            }
        }
        return s;
    }
};