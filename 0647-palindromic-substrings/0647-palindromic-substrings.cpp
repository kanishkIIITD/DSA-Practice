class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        // Checking in odd substrings
        for(int curr = 0; curr < s.length(); curr++){
            int i = curr;
            int j = curr;
            while(i >= 0 && j <= s.length()-1 && s[i] == s[j]){
                count++;
                i--;
                j++; 
            }
        }

        // Checking in even substrings
        for(int curr = 0; curr < s.length(); curr++){
            int i = curr;
            int j = curr+1;
            while(i >= 0 && j <= s.length()-1 && s[i] == s[j]){
                count++;
                i--;
                j++; 
            }
        }
        return count;
    }
};