class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto time: times){
            adj[time[0]].push_back({time[1], time[2]});
        }
        vector<int> dist(n+1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        dist[k] = 0;
        while(!pq.empty()){
            int time = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it: adj[node]){
                int adjNode = it.first;
                int weight = it.second;
                if(time + weight < dist[adjNode]){
                    dist[adjNode] = time + weight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        int maxi = INT_MIN;
        for(int i = 1; i < n+1; i++)
            maxi = max(maxi, dist[i]);
        return maxi == INT_MAX ? -1 : maxi;
    }
};