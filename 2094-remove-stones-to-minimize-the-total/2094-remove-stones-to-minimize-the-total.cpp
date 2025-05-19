class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> maxHeap;
        for(auto pile: piles)
            maxHeap.push(pile);
        while(k--){
            int top = maxHeap.top();
            maxHeap.pop();
            top = ceil(((double)top) / 2);
            maxHeap.push(top);
        }
        int ans = 0;
        while(!maxHeap.empty()){
            ans += maxHeap.top();
            maxHeap.pop();
        }
        return ans;
    }
};