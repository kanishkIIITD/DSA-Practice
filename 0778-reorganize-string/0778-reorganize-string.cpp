class Solution {
public:
    string reorganizeString(string s) {
        int hash[26] = {0};
        for (char c : s) {
            hash[c - 'a']++;
        }

        priority_queue<pair<int, char>> pq; // max-heap by freq
        for (int i = 0; i < 26; i++) {
            if (hash[i] != 0)
                pq.push({hash[i], i + 'a'});
        }

        string ans = "";
        while (pq.size() > 1) {
            auto [freq1, ch1] = pq.top(); pq.pop();
            auto [freq2, ch2] = pq.top(); pq.pop();

            ans += ch1; freq1--;
            ans += ch2; freq2--;

            if (freq1 > 0) pq.push({freq1, ch1});
            if (freq2 > 0) pq.push({freq2, ch2});
        }

        if (!pq.empty()) {
            auto [freq, ch] = pq.top(); pq.pop();
            if (freq > 1) return "";
            ans += ch;
        }

        return ans;
    }
};
