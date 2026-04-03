class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int MOD = 1e9 + 7;
        vector<vector<pair<int, int>>> adj(n);
        for(auto road: roads){
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq; 
        vector<long long> time(n, LLONG_MAX);
        vector<long long> ways(n);
        ways[0] = 1;
        time[0] = 0;
        pq.push({0, 0});
        while(!pq.empty()){
            long long t = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it: adj[node]){
                int adjNode = it.first;
                long long ti = it.second;
                if(t + ti < time[adjNode]){
                    time[adjNode] = t + ti;
                    pq.push({time[adjNode], adjNode});
                    ways[adjNode] = ways[node];
                }
                else if( t + ti == time[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
                }
            }
        }
        return ways[n-1];
    }
};