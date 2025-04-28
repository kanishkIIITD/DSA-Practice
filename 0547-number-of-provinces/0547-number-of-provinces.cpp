class Solution {
public:
    void dfs(int i, vector<int>& vis, vector<vector<int>>& isConnected){
        vis[i] = 1;
        for(int j = 0; j < vis.size(); j++){
            if(!vis[j] && isConnected[i][j]){
                dfs(j, vis, isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int provinces = 0;
        int n = isConnected.size();
        vector<int> vis(n, 0);
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                provinces++;
                dfs(i, vis, isConnected);
            }
        }
        return provinces;
    }
};