class Solution {
public:
    bool isPalindrome(int i, int j, string s){
        while(i <= j){
            if(s[i] == s[j]){
                i++;j--;
            }
            else 
                return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.length()-1;
        int count = 0;
        while(i <= j){
            if(s[i] == s[j]){
                i++;j--;
            }
            else{
                return isPalindrome(i+1,j, s) || isPalindrome(i, j-1, s);
            }
        }
        return true;
    }
};