class Solution {
public:
    bool solve(int& i, string& expression){
        if(expression[i] == 't'){
            i++;
            return true;
        }
        if(expression[i] == 'f'){
            i++;
            return false;
        }
        char ch = expression[i];
        bool ans = (ch == '&');
        if(ch == '!' || ch == '&' || ch == '|'){
            i += 2;
            while(expression[i] != ')'){
                if(expression[i] == ','){
                    i++;
                    continue;
                }
                bool nextVal = solve(i, expression);
                if(ch == '!')
                    ans = !nextVal;
                else if(ch == '&')
                    ans = ans && nextVal;
                else if(ch == '|')
                    ans = ans || nextVal;
            }
            i++;
        }
        return ans;
    }
    bool parseBoolExpr(string expression) {
        int i = 0;
        return solve(i, expression);
    }
};