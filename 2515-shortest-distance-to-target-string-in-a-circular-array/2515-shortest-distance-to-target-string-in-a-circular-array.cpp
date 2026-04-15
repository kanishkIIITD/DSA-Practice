class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();

        for (int dist = 0; dist <= n / 2; dist++) {
            int right = (startIndex + dist) % n;
            int left = (startIndex - dist % n + n) % n; 
            
            if (words[right] == target || words[left] == target) {
                return dist;
            }
        }
        
        return -1;
    }
};