class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        }
        return true;
    }
    int reverseNum(int n){
        int r = 0;
        while(n){
            int digit = n % 10;
            r = r * 10 + digit;
            n = n / 10;
        }
        return r;
    }
    int sumOfPrimesInRange(int n) {
        int r = reverseNum(n);
        int sum = 0;
        for(int i = min(r, n); i <= max(r, n); i++){
            if(isPrime(i))
                sum += i;
        }
        return sum;
    }
};