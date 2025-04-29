// class Solution {
// public:
//     int countPaths(int n, vector<vector<int>>& roads) {
//         vector<vector<pair<int, int>>> adj(n);
//         for(auto road: roads){
//             adj[road[0]].push_back({road[1], road[2]});
//             adj[road[1]].push_back({road[0], road[2]});
//         }
//         int mod = (int)(1e9 + 7);
//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//         vector<int> ways(n, 0);
//         vector<int> dist(n, 1e9);
//         pq.push({0, 0});
//         ways[0] = 1;
//         dist[0] = 0;
//         while(!pq.empty()){
//             int d = pq.top().first;
//             int node = pq.top().second;
//             pq.pop();
//             for(auto it: adj[node]){
//                 int adjNode = it.first;
//                 int w = it.second;
//                 if(d + w < dist[adjNode]){
//                     dist[adjNode] = d + w;
//                     pq.push({dist[adjNode], adjNode});
//                     ways[adjNode] = ways[node];
//                 }
//                 else if(d + w == dist[adjNode]){
//                     ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
//                 }
//             }
//         }
//         return ways[n-1] % mod;
//     }
// };
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n);
        for (const auto& road : roads) {
            int u = road[0], v = road[1], time = road[2];
            graph[u].emplace_back(v, time);
            graph[v].emplace_back(u, time);
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.emplace(0, 0);

        const int MOD = 1e9 + 7;

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if (d > dist[node]) continue;

            for (const auto& [neighbor, time] : graph[node]) {
                if (dist[node] + time < dist[neighbor]) {
                    dist[neighbor] = dist[node] + time;
                    ways[neighbor] = ways[node];
                    pq.emplace(dist[neighbor], neighbor);
                } else if (dist[node] + time == dist[neighbor]) {
                    ways[neighbor] = (ways[neighbor] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};