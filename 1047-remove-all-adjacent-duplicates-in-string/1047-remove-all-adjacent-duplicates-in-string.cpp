class Solution {
public:
    string removeDuplicates(string s) {
        // int len = s.length();
        // for(int i = 0; i < len-1; i++){
        //     int count = 0;
        //     while(s[i] == s[i+1]){
        //         count++;
        //         i++;
        //     }
        //     if(count != 0){
        //         i = i - count;
        //         if(count % 2 != 0){
        //             s.replace(i, count+1, "");
        //             len = len - count - 1;
        //         }
        //         else{
        //             s.replace(i, count, "");
        //             len = len - count;
        //         }
        //         i = -1;
        //     }
        // }
        // return s;
        string ans;
        for(int i = 0; i < s.length(); i++){
            if(!ans.empty() && ans.back() == s[i])
                ans.pop_back();
            else    
                ans.push_back(s[i]);
        }
        return ans;
    }
};