class Solution {
public:
    bool sumGame(string num) {
        int leftsum = 0, rightsum = 0, left = 0, right = 0;
        int n = num.size();
        for(int i = 0; i < n; i++){
            if(i < n/2){
                if(num[i] == '?')
                    left++;
                else
                    leftsum += num[i] - '0';
            }
            else{
                if(num[i] == '?')
                    right++;
                else
                    rightsum += num[i] - '0';
            }
        }
        return (leftsum - rightsum) * 2 != 9 * (right - left);
    }
};