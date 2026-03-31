class Solution {
public:
    void bfs(int node, vector<vector<int>>& isConnected, vector<int>& vis){
        queue<int> q;
        q.push(node);
        vis[node] = 1;
        while(!q.empty()){
            int front = q.front(); q.pop();
            for(int i = 0; i < isConnected.size(); i++){
                if(isConnected[front][i] == 1 && !vis[i]){
                    vis[i] = 1;
                    q.push(i);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<int> vis(V);
        int count = 0;
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                count++;
                bfs(i, isConnected, vis);
            }
        }
        return count;
    }
};