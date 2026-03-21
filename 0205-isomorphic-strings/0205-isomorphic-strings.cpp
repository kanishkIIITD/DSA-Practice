class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> s2t;
        unordered_map<char, char> t2s;

        for (int i = 0; i < s.size(); i++) {
            // Check if s[i] maps to a different t[i]
            if (s2t.count(s[i]) && s2t[s[i]] != t[i]) return false;
            // Check if t[i] was already mapped to a different s[i]
            if (t2s.count(t[i]) && t2s[t[i]] != s[i]) return false;

            s2t[s[i]] = t[i];
            t2s[t[i]] = s[i];
        }
        return true;
    }
};