class Solution {
public:
    void removeOccRE(string&s, string&part){
        int index = s.find(part);
        if(index != string::npos){
            s.erase(index, part.length());
        }
        else return;
        removeOccRE(s, part);
    }
    string removeOccurrences(string s, string part) {
        removeOccRE(s, part);
        return s;
    }
};