class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi = INT_MIN;
        int sum = 0;
        for(auto g: gain){
            sum += g;
            maxi = max(maxi, sum);
        }
        return maxi <= 0 ? 0 : maxi;
    }
};