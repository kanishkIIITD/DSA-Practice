class Solution {
public:
    bool checkValidString(string s) {
        int mini = 0, maxi = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                mini++;
                maxi++;
            }
            else if(s[i] == ')'){
                mini = max(0, mini - 1);
                maxi--;
            }
            else{
                mini = max(0, mini - 1);
                maxi++;
            }
            if(maxi < 0)
                return false;
        }
        return mini == 0;
    }
};