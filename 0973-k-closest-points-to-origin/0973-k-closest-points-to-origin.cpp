class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue< pair<int, int>> pq;
        for(int i = 0; i < k; i++){
            int x = points[i][0];
            int y = points[i][1];
            int sq = x * x + y * y;
            pq.push({sq, i});
        }
        for(int i = k; i < points.size(); i++){
            int x = points[i][0];
            int y = points[i][1];
            int sq = x * x + y * y;
            if(sq < pq.top().first){
                pq.pop();
                pq.push({sq, i});
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
};