class Solution {
public:
    int solve(int n){
        if(n <= 99)
            return 0;
        vector<int> num;
        while(n){
            num.push_back(n%10);
            n = n/10;
        }
        int count = 0;
        for(int i = 1; i < num.size()-1; i++){
            if((num[i] < num[i+1] && num[i] < num[i-1]) || (num[i] > num[i+1] && num[i] > num[i-1]))
                count++;
        }
        return count;
    }
    int totalWaviness(int num1, int num2) {
        int count = 0;
        for(int i = num1; i <= num2; i++){
            count += solve(i);
        }
        return count;
    }
};