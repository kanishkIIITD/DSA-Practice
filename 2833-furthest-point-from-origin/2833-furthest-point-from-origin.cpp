class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int count_l = 0, count_r = 0, count_und = 0;
        for(auto &ch: moves){
            if(ch == 'L')
                count_l++;
            else if(ch == 'R')
                count_r++;
            else
                count_und++;
        }
        return abs(count_l - count_r) + count_und;
    }
};