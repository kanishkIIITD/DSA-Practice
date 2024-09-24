class Solution {
public:
    string removeDuplicates(string s) {
        // if(s.lenght() <= 1)
        //     return s;
        
        string ans = "";
        int i = 0;
        while(i < s.length()){             
            if(ans.length() > 0){
                if(s[i] == ans[ans.length()-1]){
                    ans.pop_back();
                }
                else{
                    ans.push_back(s[i]);
                }
            }
            else{
                ans.push_back(s[i]);
            }
            i++;
        }
        return ans;
    }
};