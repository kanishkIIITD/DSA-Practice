class Solution {
public:
    static bool cmp(pair<int, char> p1, pair<int, char> p2){
        if(p1.first < p2.first)
            return false;
        if(p1.first > p2.first)
            return true;
        return p1.second < p2.second;
    }
    string frequencySort(string s) {
        pair<int, char> hash[256];
        for(int i = 0; i < 256; i++){
            hash[i] = {0, (char)i};
        }
        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            hash[(int)ch].first++;
        }
        sort(hash, hash+256, cmp);

        string ans;
        for (int i = 0; i < 256; i++) {
            while (hash[i].first > 0){
                ans.push_back(hash[i].second);
                hash[i].first--;
            }
        }

        return ans;
    }
};