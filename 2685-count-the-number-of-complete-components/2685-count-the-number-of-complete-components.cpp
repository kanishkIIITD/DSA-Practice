class Solution {
public:
    void bfs(int node, vector<vector<int>>& adj, vector<int>& degree, int &count, vector<int>& vis){
        vis[node] = 1;
        queue<int> q;
        q.push(node);
        int c = 0;
        vector<int> component;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            c++;
            component.push_back(front);
            for(auto it: adj[front]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        for(auto com: component){
            if(degree[com] != c-1)
                return;
        }
        count++;
        return;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> degree(n);
        for(auto e: edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }
        vector<int> vis(n);
        int count = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i])
                bfs(i, adj, degree, count, vis);
        }
        return count;
    }
};