class Solution {
public:
    bool bfs(int src, vector<vector<int>>& graph, vector<int>& vis, int& color){
        queue<int> q;
        q.push(src);
        vis[src] = color;
        color = !color;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                int node = q.front(); q.pop();
                for(auto it: graph[node]){
                    if(vis[it] == -1){
                        q.push(it);
                        vis[it] = color;
                    }
                    else if(vis[it] != color)
                        return false;
                }
            }
            color = !color;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);
        int color = 0;
        for(int i = 0; i < n; i++){
            if(vis[i] == -1){
                if(!bfs(i, graph, vis, color))
                    return false;
            }
        }
        return true;
    }
};