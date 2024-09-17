class Solution {
public:
    vector<string> strToVector(string s){
        string temp = "";
        vector<string> str;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ' '){
                str.push_back(temp);
                temp = "";
            }
            else{
                temp += s[i];
            }
        }
        str.push_back(temp);
        return str;
    }
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> str = strToVector(s1 + " " + s2);
        unordered_map<string, int> hash;
        for(int i = 0; i < str.size(); i++){
            hash[str[i]] ++;
        }
        vector<string> ans;
        for(int i = 0; i < str.size(); i++){
            if(hash[str[i]] == 1){
                ans.push_back(str[i]);
            }
        }
        return ans;
    }
};