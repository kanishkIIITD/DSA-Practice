class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < piles.size(); i++)
            pq.push({piles[i], i});
        for(int i = 0; i < k; i++){
            int value = pq.top().first;
            int index = pq.top().second;
            pq.pop();
            piles[index] -= piles[index] / 2;
            pq.push({piles[index], index});
        }
        int sum = 0;
        for(int i = 0; i < piles.size(); i++)
            sum += piles[i];
        return sum;
    }
};