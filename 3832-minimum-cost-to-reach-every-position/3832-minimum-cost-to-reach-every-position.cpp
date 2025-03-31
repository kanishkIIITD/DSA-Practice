class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        int n = cost.size();
        std::vector<int> answer(n, INT_MAX);
        
        for (int i = 0; i < n; i++) {
            answer[i] = cost[i];
            if (i > 0) answer[i] = std::min(answer[i], answer[i - 1]); 
        }
        
        return answer;
    }
};