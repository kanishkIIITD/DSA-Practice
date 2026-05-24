class Solution {
public:
    int dfs(int start, vector<int>& arr, int d, vector<int>& memo){
        if(memo[start] != 0)
            return memo[start];
        int maxi = 1;
        int n = arr.size();
        for(int j = start+1; j <= min(n-1, start+d); j++){
            if(arr[j] >= arr[start])
                break;
            maxi = max(maxi, 1 + dfs(j, arr, d, memo));
        }
        for(int j = start-1; j >= max(0, start-d); j--){
            if(arr[j] >= arr[start])
                break;
            maxi = max(maxi, 1 + dfs(j, arr, d, memo));
        }
        return memo[start] = maxi;
    }
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> memo(n);
        int maxi = INT_MIN;
        for(int i = 0; i < n; i++){
            maxi = max(maxi, dfs(i, arr, d, memo));
        }
        return maxi;
    }
};