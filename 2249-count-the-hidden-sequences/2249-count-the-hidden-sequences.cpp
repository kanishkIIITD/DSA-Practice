class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = differences.size();
        long long arrVal = 0;
        long long mini = 0;
        long long maxi = 0;
        for(int i = 0; i < n; i++){
            arrVal += differences[i];
            mini = arrVal < mini ? arrVal : mini;
            maxi = arrVal > maxi ? arrVal : maxi;
        }
        if(maxi-mini > upper - lower)
            return 0;
        else
            return ((upper-lower) - (maxi-mini) + 1);
    }
};