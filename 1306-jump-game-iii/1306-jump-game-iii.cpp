class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q;
        int n = arr.size();
        vector<int> vis(n);
        q.push(start);
        vis[start] = 1;
        while(!q.empty()){
            int i = q.front();
            q.pop();
            if(arr[i] == 0)
                return true;
            if(i - arr[i] >= 0 && !vis[i - arr[i]]){
                q.push(i - arr[i]);
                vis[i - arr[i]] = 1;
            }
            if(i + arr[i] < n && !vis[i + arr[i]]){
                q.push(i + arr[i]);
                vis[i + arr[i]] = 1;
            }
        }
        return false;
    }
};