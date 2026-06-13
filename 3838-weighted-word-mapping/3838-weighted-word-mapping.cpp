class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for(auto word: words){
            int w = 0;
            for(auto ch: word){
                w += weights[ch - 'a'];
            }
            w %= 26;
            w = 25 - w;
            ans += w + 'a';
        }
        return ans;
    }
};