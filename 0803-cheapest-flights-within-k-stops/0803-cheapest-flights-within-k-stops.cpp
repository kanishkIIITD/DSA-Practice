class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto flight: flights){
            adj[flight[0]].push_back({flight[1], flight[2]});
        }
        vector<int> dist(n, 1e9);
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        dist[src] = 0;

        while(!q.empty()){
            auto it = q.front(); q.pop();
            int stop = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            if(stop > k)
                continue;
            for(auto iter: adj[node]){
                int adjNode = iter.first;
                int edjW = iter.second;
                if(cost + edjW < dist[adjNode] && stop <= k){
                    dist[adjNode] = cost + edjW;
                    q.push({stop+1, {adjNode, dist[adjNode]}});
                }
            }
        }
        if(dist[dst] == 1e9)
            return -1;
        else
            return dist[dst];
    }
};