class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        if (n <= 1)
            return n;
        int index = 0;
        int prev = 0;
        int i = 1;
        int count = 1;
        while (i < n) {
            if (chars[prev] == chars[i]) {
                count++;
                prev++;
                i++;
            } else if (chars[prev] != chars[i] && count > 1) {
                vector<int> digits;
                while (count) {
                    digits.push_back(count % 10);
                    count = count / 10;
                }
                reverse(digits.begin(), digits.end());
                chars[index] = chars[prev];
                index++;
                for (int j = 0; j < digits.size(); j++) {
                    chars[index] = digits[j] + '0';
                    index++;
                }
                count = 1;
                prev++;
                i++;
            } else {
                chars[index] = chars[prev];
                index++;
                prev++;
                i++;
            }
        }

        chars[index] = chars[prev];
        index++;
        if (count > 1) {
            vector<int> digits;
            while (count) {
                digits.push_back(count % 10);
                count = count / 10;
            }
            reverse(digits.begin(), digits.end());

            for (int j = 0; j < digits.size(); j++) {
                chars[index] = digits[j] + '0';
                index++;
            }
        }

        for (int i = 0; i < n; i++)
            cout << chars[i];
        return index;
    }
};