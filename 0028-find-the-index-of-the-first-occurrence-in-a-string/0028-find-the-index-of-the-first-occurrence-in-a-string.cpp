class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() > haystack.size())
            return -1;
        int j = 0;
        for(int i = 0; i < haystack.size(); i++){
            while(j < needle.size() && haystack[i] == needle[j]){
                i++;
                j++;
            }
            if(j == needle.size())
                return i - j;
            else{
                i = i - j;
                j = 0;
            }
        }
        return -1;
    }
};