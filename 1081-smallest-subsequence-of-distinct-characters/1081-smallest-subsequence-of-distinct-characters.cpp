class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> hash(26);
        vector<bool> seen(26, false);
        string ans = "";
        for(int i = 0; i < s.size(); i++)
            hash[s[i] - 'a'] = i;
        for(int i = 0; i < s.size(); i++){
            int curr = s[i] - 'a';
            if(seen[curr])
                continue;
            while(!ans.empty() && s[i] < ans.back() && hash[ans.back() - 'a'] > i){
                seen[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            ans.push_back(s[i]);
            seen[curr] = true;
        }
        return ans;
    }
};