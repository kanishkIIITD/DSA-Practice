class Solution {
public:
    int compress(vector<char>& chars) {
        if (chars.empty()) return 0;

        int index = 0, prev = 0, i = 1, count = 1;
        while(i < chars.size()){
            if(chars[prev] == chars[i]){
                count++;
            }
            else{
                chars[index++] = chars[prev];
                if(count > 1){
                    string countStr = to_string(count);
                    for(auto c: countStr)
                        chars[index++] = c;
                    count = 1;
                }
            }
            prev++;
            i++;
        }

        chars[index++] = chars[prev];
        if(count > 1){
            string countStr = to_string(count);
            for(auto c: countStr)
                chars[index++] = c;
        }

        return index;
    }
};