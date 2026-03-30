class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int> hashEven(256);
        vector<int> hashOdd(256);
        for(int i = 0; i < s1.size(); i++){
            if(i % 2 == 0)
                hashEven[s1[i]]++;
            else
                hashOdd[s1[i]]++;
        }
        for(int i = 0; i < s2.size(); i++){
            if(i % 2 == 0)
                hashEven[s2[i]]--;
            else
                hashOdd[s2[i]]--;
        }
        for(int i = 0; i < 256; i++)
            if(hashOdd[i] != 0 || hashEven[i] != 0)
                return false;
        return true;
    }
};