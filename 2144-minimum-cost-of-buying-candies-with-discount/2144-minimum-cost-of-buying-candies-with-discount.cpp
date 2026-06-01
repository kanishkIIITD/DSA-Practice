class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        int i = cost.size()-1;
        int total = 0;
        while(i >= 0){
            int big = cost[i];
            int small = 0;
            if(i-1 >= 0)
                small = cost[i-1];
            total += big + small;
            i -= 3;
        }
        return total;
    }
};