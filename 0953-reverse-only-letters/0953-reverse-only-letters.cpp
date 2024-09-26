class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i = 0; 
        int j = s.length()-1;
        while(i <= j){
            if(isalpha(s[i]) && isalpha(s[j])){
                char temp = s[i];
                s[i] = s[j];
                s[j] = temp;
                i++;j--;
            }
            else if(isalpha(s[i])){
                j--;
            }
            else
                i++;
        }
        return s;
    }
};