class Solution {
public:
    int dijkstra(int src, int n, vector<vector<pair<int, int>>> &adj, int distanceThreshold){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n, 1e8);
        dist[src] = 0;
        pq.push({0, src});
        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto& it: adj[node]){
                if(d + it.second < dist[it.first]){
                    dist[it.first] = d + it.second;
                    pq.push({dist[it.first], it.first});
                }
            }
        }
        int count = 0;
        for(int i = 0; i < n; i++){
            if(dist[i] <= distanceThreshold)
                count++;
        }
        return count;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // vector<vector<int>> cost(n, vector<int>(n, 1e8));
        // for(auto &edge: edges){
        //     cost[edge[0]][edge[1]] = edge[2];
        //     cost[edge[1]][edge[0]] = edge[2];
        // }
        // for(int i = 0; i < n; i++)
        //     cost[i][i] = 0;
        // for(int k = 0; k < n; k++){
        //     for(int i = 0; i < n; i++){
        //         for(int j = 0; j < n; j++){
        //             if(cost[i][k] != 1e8 && cost[k][j] != 1e8)
        //                 cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
        //         }
        //     }
        // }
        // int mini = INT_MAX, minIdx = -1;
        // for(int i = 0; i < n; i++){
        //     int total = 0;
        //     for(int j = 0; j < n; j++){
        //         if(cost[i][j] <= distanceThreshold)
        //             total++;
        //     }
        //     if(total <= mini){
        //         mini = total;
        //         minIdx = i;
        //     }
        // }
        // return minIdx;

        vector<vector<pair<int, int>>> adj(n);
        for(auto& edge: edges){
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }
        int mini = INT_MAX, minCity = -1;
        for(int i = 0; i < n; i++){
            int count = dijkstra(i, n, adj, distanceThreshold);
            if(count <= mini){
                mini = count;
                minCity = i;
            }
        }
        return minCity;
    }
};