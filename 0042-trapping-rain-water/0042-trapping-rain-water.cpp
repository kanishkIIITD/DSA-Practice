class Solution {
public:
    int getMax(vector<int>&height, int start, int end){
        int maxi = INT_MIN;
        for(int i = start; i <= end; i++)
            maxi = height[i] > maxi ? height[i] : maxi;
        return maxi;
    }
    int trap(vector<int>& height) {
        // Brute Force
        // int n = height.size();
        // int ans = 0;
        // for(int i = 0; i < n; i++){
        //     int water = min(getMax(height, 0, i), getMax(height, i, n-1)) - height[i];
        //     ans += water;
        // }
        // return ans;

        // Optimized
        int n = height.size();
        vector<int> prefixMax(n,0);
        vector<int> suffixMax(n,0);

        prefixMax[0] = height[0];
        suffixMax[n-1] = height[n-1];

        for(int i = 1; i < n; i++){
            prefixMax[i] = height[i] > prefixMax[i-1] ? height[i] : prefixMax[i-1];
        }
        for(int i = n-2; i >= 0; i--){
            suffixMax[i] = height[i] > suffixMax[i+1] ? height[i] : suffixMax[i+1];
        }
        
        int ans = 0;

        for(int i = 0; i < n; i++){
            ans += min(prefixMax[i], suffixMax[i]) - height[i];
        }
        return ans;
    }
};