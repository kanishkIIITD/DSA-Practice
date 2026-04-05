class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for(int i = 0; i < moves.size(); i++){
            char ch = moves[i];
            if(ch == 'U')
                x--;
            else if(ch == 'R')
                y++;
            else if(ch == 'D')
                x++;
            else if(ch == 'L')
                y--;
        }
        if(x == 0 && y == 0)
            return true;
        return false;
    }
};