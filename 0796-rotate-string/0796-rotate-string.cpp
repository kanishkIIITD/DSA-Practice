class Solution {
public:
    void rotate(string& s){
        if(s.size() <= 1)
            return;
        s = s.substr(1, s.size()-1) + s[0];
        return;
    }
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size())
            return false;
        if(s == goal)
            return true;
        for(int i = 0; i < s.size(); i++){
            rotate(s);
            if(s == goal)
                return true;
        }
        return false;
    }
};