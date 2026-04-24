class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int, char>> pq;
        vector<int> hash(26);
        for(int i = 0; i < s.size(); i++){
            hash[s[i] - 'a'] += 1;
        }
        for(int i = 0; i < 26; i++){
            if(hash[i] > 0)
                pq.push({hash[i], i + 'a'});
        }
        string ans = "";
        while(pq.size() > 1){
            auto [freq1, ch1] = pq.top(); pq.pop();
            auto [freq2, ch2] = pq.top(); pq.pop();
            ans += ch1;
            ans += ch2;
            if(freq1-1 > 0)
                pq.push({freq1-1, ch1});
            if(freq2-1 > 0)
                pq.push({freq2-1, ch2});
        }
        if(!pq.empty()){
            auto [freq, ch] = pq.top(); pq.pop();
            if(freq > 1)
                return "";
            ans += ch;
        }
        return ans;
    }
};