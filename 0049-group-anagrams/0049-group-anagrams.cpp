class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m;
        for(auto str: strs){
            string temp = str.substr(0, str.length());
            sort(temp.begin(), temp.end());
            m[temp].push_back(str);
        }

        vector<vector<string>> ans;

        for(auto i:m){
            ans.push_back(i.second);
        }
        
        return ans;
    }
};