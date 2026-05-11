class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> cost(n, vector<int>(n, 1e8));
        for(auto &edge: edges){
            cost[edge[0]][edge[1]] = edge[2];
            cost[edge[1]][edge[0]] = edge[2];
        }
        for(int i = 0; i < n; i++)
            cost[i][i] = 0;
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(cost[i][k] != 1e8 && cost[k][j] != 1e8)
                        cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
                }
            }
        }
        int mini = INT_MAX, minIdx = -1;
        for(int i = 0; i < n; i++){
            int total = 0;
            for(int j = 0; j < n; j++){
                if(cost[i][j] <= distanceThreshold)
                    total++;
            }
            if(total <= mini){
                mini = total;
                minIdx = i;
            }
        }
        return minIdx;
    }
};