class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st;
        for(auto word: wordList)
            st.insert(word);
        if(st.find(endWord) == st.end())
            return 0;
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        while(!q.empty()){
            string word = q.front().first;
            int level = q.front().second;
            q.pop();
            for(int i = 0; i < word.size(); i++){
                string curr = word;
                for(char ch = 'a'; ch <= 'z'; ch++){
                    curr[i] = ch;
                    if(curr == endWord)
                        return level+1;
                    if(st.find(curr) != st.end()){
                        q.push({curr, level + 1});
                        st.erase(curr);
                    }
                }
            }
        }
        return 0;
    }
};