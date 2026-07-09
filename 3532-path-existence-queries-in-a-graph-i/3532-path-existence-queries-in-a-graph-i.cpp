class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int c = 0;
        vector<int> g(n);
        for(int i = 1; i < n; i++){
            if(abs(nums[i] - nums[i-1]) > maxDiff)
                c++;
            g[i] = c;
        }
        vector<bool> ans;
        for(auto q: queries){
            int u = q[0];
            int v = q[1];
            ans.push_back(g[u] == g[v]);
        }
        return ans;
    }
};