class Solution {
public:
    int getTime(vector<int>& start1, vector<int>& dur1, vector<int>& start2, vector<int>& dur2){
        int minEnd1 = INT_MAX;
        for(int i = 0; i < start1.size(); i++)
            minEnd1 = min(minEnd1, start1[i] + dur1[i]);
        int minEndTotal = INT_MAX;
        for(int i = 0; i < start2.size(); i++){
            int maxi = max(minEnd1, start2[i]);
            minEndTotal = min(minEndTotal, maxi + dur2[i]);
        }
        return minEndTotal;
    }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int land = getTime(landStartTime, landDuration, waterStartTime, waterDuration);
        int water = getTime(waterStartTime, waterDuration, landStartTime, landDuration);
        return min(land, water);
    }
};