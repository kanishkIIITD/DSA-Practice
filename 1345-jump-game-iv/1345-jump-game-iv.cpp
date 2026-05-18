class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++)
            mp[arr[i]].push_back(i);
        vector<int> vis(n);
        queue<pair<int, int>> q;
        q.push({0, 0});
        vis[0] = 1;
        while(!q.empty()){
            int c = q.front().first;
            int s = q.front().second;
            q.pop();
            if(c == n-1)
                return s;
            if(c-1 >= 0 && !vis[c-1]){
                q.push({c-1, s+1});
                vis[c-1] = 1;
            }
            if(c+1 < n && !vis[c+1]){
                q.push({c+1, s+1});
                vis[c+1] = 1;
            }
            for(auto &it: mp[arr[c]]){
                if(!vis[it]){
                    q.push({it, s+1});
                    vis[it] = 1;
                }
            }
            mp[arr[c]].clear();
        }
        return -1;
    }
};