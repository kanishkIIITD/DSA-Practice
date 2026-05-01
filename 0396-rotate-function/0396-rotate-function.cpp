class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        // fp -> f(prev), fc -> f(curr)
        int fp = 0, total = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            total += nums[i];
            fp += i * nums[i];
        }
        int maxi = fp, fc = 0;
        for(int i = 1; i < n; i++){
            fc = fp + total - n * nums[n - i];
            maxi = max(maxi, fc);
            fp = fc;
        }
        return maxi;
    }
};