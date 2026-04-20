class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int ans = 0;
        for(int i = 0; i < colors.size(); i++){
            int maxi = 0;
            for(int j = i+1; j < colors.size(); j++){
                if(colors[i] != colors[j])
                    maxi = max(maxi, abs(i - j));
            }
            ans = max(ans, maxi);
        }
        return ans;
    }
};