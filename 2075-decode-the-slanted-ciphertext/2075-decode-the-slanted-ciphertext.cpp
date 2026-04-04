class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int cols = encodedText.size() / rows;
        string ans = "";

        for (int sc = 0; sc < cols; sc++) {
            int i = 0;
            int j = sc;

            while (i < rows && j < cols) {
                int index = i * cols + j;
                ans += encodedText[index];
                i++;
                j++;
            }
        }

        while (!ans.empty() && ans.back() == ' ') {
            ans.pop_back();
        }

        return ans;
    }
};