class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> change(3); // {5, 10, 20};
        for(auto bill: bills){
            if(bill == 5){
                change[0]++;
            }
            else if(bill == 10){
                if(change[0] == 0)
                    return false;
                change[0]--;
                change[1]++;
            }
            else{
                change[2]++;
                if(change[0] > 0 && change[1] > 0){
                    change[0]--;
                    change[1]--;
                }
                else if(change[0] > 2){
                    change[0] -= 3;
                }
                else
                    return false;
            }
        }
        return true;
    }
};