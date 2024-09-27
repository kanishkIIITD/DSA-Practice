class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.length() < needle.length())
            return -1;
        int i = 0;
        while(i <= haystack.length() - needle.length()){
            int j = 0;
            while(j < needle.length()){
                if(haystack[i] != needle[j])
                    break;
                j++;
                i++;
            }
            i = i-j; // This line helps to go back so that we don't miss any substrs
            if(j == needle.length())
                return i;
            i++;
        }
        return -1;
    }
};