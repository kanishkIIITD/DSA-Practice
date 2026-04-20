class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int ans = 0;
        int i = 0, j = colors.size() - 1;
        while(i < j){
            if(colors[i] != colors[j])
                break;
            i++;
        }
        ans = max(ans, abs(i - j));
        i = 0;
        while(j > i){
            if(colors[i] != colors[j])
                break;
            j--;
        }
        ans = max(ans, abs(i - j));
        return ans;
    }
};