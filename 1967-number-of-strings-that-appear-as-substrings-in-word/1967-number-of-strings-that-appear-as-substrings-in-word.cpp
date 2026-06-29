class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
        for(auto p: patterns){
            if(word.find(p) !=std::string::npos)
                count++;
        }
        return count;
    }
};