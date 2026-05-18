class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq;
        long long sum = 0;
        for(auto& num: target){
            sum += num;
            pq.push(num);
        }
        while(pq.top() > 1){
            long long maxi = pq.top();
            pq.pop();
            long long rest = sum - maxi;
            if(rest == 1)
                return true;
            if(rest == 0 || maxi <= rest)
                return false;
            long long prev = maxi % rest;
            if(prev == 0)
                return false;
            pq.push(prev);
            sum = sum - maxi + prev;
        }
        return true;
    }
};