class Solution {
public:
    vector<int> solve(int n){
        int sum = 0, prod = 1;
        while(n){
            int digit = n % 10;
            sum += digit;
            prod *= digit;
            n /= 10;
        }
        return {sum, prod};
    }
    bool checkDivisibility(int n) {
        vector<int> a = solve(n);
        int sum = a[0] + a[1];
        return n % sum == 0;
    }
};