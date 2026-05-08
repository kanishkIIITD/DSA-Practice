class Solution {
public:
    bool isPrime(int n) {
        if (n <= 3) return n > 1;
        if (n % 2 == 0 || n % 3 == 0) return false;
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) return false;
        }
        return true;
    }
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1)
            return 0;
        int maxi = 0;
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++){
            mp[nums[i]].push_back(i);
            maxi = max(maxi, nums[i]);
        }
        vector<int> vis(n);
        queue<pair<int, int>> q;
        unordered_set<int> used;
        q.push({0, 0});
        vis[0] = 1;
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if(i == n-1)
                return j;
            if(i-1 >= 0 && !vis[i-1]){
                q.push({i-1,  j+1});
                vis[i-1] = 1;
            }
            if(i+1 < n && !vis[i+1]){
                q.push({i+1, j+1});
                vis[i+1] = 1;
            }
            if(isPrime(nums[i]) && !used.count(nums[i])){
                used.insert(nums[i]);
                int p = nums[i];
                for(int k = p; k <= maxi; k += p){
                    if(mp.count(k)){
                        for(int m: mp[k]){
                            if(!vis[m]){
                                q.push({m, j+1});
                                vis[m] = 1;
                            }
                        }
                        mp.erase(k);
                    }
                }
            }
        }
        return -1;
    }
};