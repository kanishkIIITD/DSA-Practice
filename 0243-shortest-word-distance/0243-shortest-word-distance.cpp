class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int n = wordsDict.size();
        int index1 = -1, index2 = -1;
        int ans = INT_MAX;
        for(int i=0; i<n; i++) {
            if(word1 == wordsDict[i]) {
                index1 = i;
            }

            if(word2 == wordsDict[i]) {
                index2 = i;
            }

            if(index1 != -1 && index2 != -1) {

                ans = min(ans, abs(index1 - index2));
            }
        }
        return ans;
    }
};