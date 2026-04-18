class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> mp;
        int j = 0, count = 0;
        for(int i = 0; i < s.size(); i++){
            mp[s[i]]++;
            while(mp.size() == 3){
                count += (s.size() - i);
                mp[s[j]]--;
                if(mp[s[j]] == 0)
                    mp.erase(s[j]);
                j++;
            }
        }
        return count;
    }
};