class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if(a > 0) pq.push({a, 'a'});
        if(b > 0) pq.push({b, 'b'});
        if(c > 0) pq.push({c, 'c'});
        string ans = "";
        while(!pq.empty()){
            auto [freq1, ch1] = pq.top(); pq.pop();
            int n = ans.size();
            if(n >= 2 && ans[n-1] == ch1 && ans[n-2] == ch1){
                if(pq.empty())
                    break;
                auto[freq2, ch2] = pq.top(); pq.pop();
                ans += ch2;
                if(freq2-1 > 0)
                    pq.push({freq2-1, ch2}); 
                pq.push({freq1, ch1});
            }
            else{
                ans += ch1;
                if(freq1-1 > 0)
                    pq.push({freq1-1, ch1});
            }
        }
        return ans;
    }
};