class Solution {
public:
    long long sumAndMultiply(int n) {
        int x = 0;
        int sum = 0;
        while(n){
            int d = n % 10;
            if(d != 0){
                sum += d;
                x = x * 10 + d;
            }
            n /= 10;
        }
        long long y = 0;
        while(x){
            int d = x % 10;
            y = y * 10 + d;
            x /= 10;
        }
        long long ans = y * sum;
        return ans;
    }
};