class Solution {
public:
    bool dfs(int src, vector<int>& vis, vector<int>& pathVis, vector<vector<int>>& adj){
        vis[src] = 1;
        pathVis[src] = 1;
        for(auto it: adj[src]){
            if(!vis[it]){
                if(dfs(it, vis, pathVis, adj)) return true;
            }
            else if(pathVis[it])
                return true;
        }
        pathVis[src] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> vis(V);
        vector<int> pathVis(V);
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs(i, vis, pathVis, graph);
            }
        }
        vector<int> ans;
        for(int i = 0; i < V; i++){
            if(pathVis[i] == 0)
                ans.push_back(i);
        }
        return ans;
    }
};