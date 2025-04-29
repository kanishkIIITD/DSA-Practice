class Solution {
public:
    bool bfs(int start, vector<int>&vis, vector<vector<int>>&graph){
        queue<int> q;
        q.push(start);
        vis[start] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it: graph[node]){
                if(vis[it] == -1){
                    q.push(it);
                    vis[it] = !vis[node];
                }
                else if(vis[it] == vis[node])
                    return false;
            }
        }
        return true;
    }
    bool dfs(int node, int color, vector<int>& vis, vector<vector<int>>& graph) {
        vis[node] = color;
        for(int neighbor : graph[node]) {
            if(vis[neighbor] == -1) {
                // Propagate failure upward immediately
                if(!dfs(neighbor, !color, vis, graph)) {
                    return false;
                }
            }
            else if(vis[neighbor] == color) {
                return false; // Direct conflict
            }
        }
        return true; // All neighbors validated
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> vis(graph.size(), -1);
        for(int i = 0; i < graph.size(); i++){
            if(vis[i] == -1)
                // if(!bfs(i, vis, graph))
                if(!dfs(i, 0, vis, graph))
                    return false;
        }
        return true;
    }
};