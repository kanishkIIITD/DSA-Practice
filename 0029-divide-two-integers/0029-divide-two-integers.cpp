class Solution {
public:
    int divide(int dividend, int divisor) {
        // Edge case: Handle overflow
        if (dividend == INT_MIN && divisor == -1) 
            return INT_MAX; // To prevent overflow

        // Determine the sign of the result
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

        // Convert both dividend and divisor to long to handle edge cases
        long long absDividend = abs((long long)dividend);
        long long absDivisor = abs((long long)divisor);

        long long ans = 0;
        long long s = 0;
        long long e = absDividend;

        while (s <= e) {
            long long m = s + (e - s) / 2;
            if (m * absDivisor == absDividend) {
                return sign * m;
            } else if (m * absDivisor > absDividend) {
                e = m - 1;
            } else {
                ans = m;
                s = m + 1;
            }
        }

        return sign * ans; // Apply sign to the result
    }
};
