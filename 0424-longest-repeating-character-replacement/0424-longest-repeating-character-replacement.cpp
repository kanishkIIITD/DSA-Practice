class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> hash(26, 0); // Frequency map for A-Z
        int j = 0;
        int maxi = 0;
        int maxFreq = 0; // Tracks the count of the most frequent character in the window
        
        for(int i = 0; i < s.size(); i++) {
            // 1. Add the current character to our window
            hash[s[i] - 'A']++;
            
            // 2. Update the highest frequency we've seen in this window
            maxFreq = max(maxFreq, hash[s[i] - 'A']);
            
            // 3. Check if the current window is valid
            // Window length is (i - j + 1). 
            // If the number of letters we NEED to replace is greater than k, shrink the window.
            while((i - j + 1) - maxFreq > k) {
                hash[s[j] - 'A']--; // Remove the left-most character from our counts
                j++;                // Shrink the window
            }
            
            // 4. Calculate the max window size dynamically
            maxi = max(maxi, i - j + 1);
        }
        
        return maxi;
    }
};