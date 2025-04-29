class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto flight: flights){
            int u = flight[0];
            int v = flight[1];
            int w = flight[2];
            adj[u].push_back({v, w});
        }
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({0, src, 0});
        dist[src][0] = 0;

        while(!pq.empty()){
            auto [cost, u, stops] = pq.top();
            pq.pop();

            if (u == dst) return cost;
            if (stops > k) continue;

            for (auto [v, w] : adj[u]) {
                int new_cost = cost + w;
                int new_stops = stops + 1;

                if (new_stops > k + 1) continue;

                if (new_cost < dist[v][new_stops]) {
                    dist[v][new_stops] = new_cost;
                    pq.push({new_cost, v, new_stops});
                }
            }
        }
        return -1;
    }
};