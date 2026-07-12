class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
        int n = arr.size();
        for(int i = 0; i < n; i++)
            pq.push({arr[i], i});
        int last = 0;
        int rank = 0;
        while(!pq.empty()){
            int top = pq.top().first;
            int ind = pq.top().second;
            pq.pop();
            if(rank == 0 || top > last){
                last = top;
                rank++;
            }
            arr[ind] = rank;
        }
        return arr;
    }
};