class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i = 0; 
        int j = s.length()-1;
        while(i <= j){
            // if(!(s[i] >= 'a' && s[i] <= 'z') || !(s[i] >= 'A' && s[i] <= 'Z'))
            //     i++;
            // if(!(s[j] >= 'a' && s[j] <= 'z') || !(s[j] >= 'A' && s[j] <= 'Z'))
            //     j--;
            // if(i <= j){
            //     // swap(s[i], s[j]);
            //     char temp = s[i];
            //     s[i] = s[j];
            //     s[j] = temp;
            //     i++;j--;
            // }
            if(((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) && ((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= 'A' && s[j] <= 'Z'))){
                char temp = s[i];
                s[i] = s[j];
                s[j] = temp;
                i++;j--;
            }
            else if(((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))){
                j--;
            }
            else
                i++;
        }
        return s;
    }
};