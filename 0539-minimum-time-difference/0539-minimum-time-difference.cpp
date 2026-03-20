class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> totalMinutes;
        for(int i = 0; i < timePoints.size(); i++){
            string curr = timePoints[i];
            int hours = stoi(curr.substr(0, 2));
            int minutes = stoi(curr.substr(3, 5));
            int totalMinute = 60 * hours + minutes;
            totalMinutes.push_back(totalMinute);
        }
        sort(totalMinutes.begin(), totalMinutes.end());
        int mini = INT_MAX;
        for(int i = 1; i < totalMinutes.size(); i++){
            mini = min(mini, totalMinutes[i] - totalMinutes[i-1]);
        }
        mini = min(mini, 1440 - (totalMinutes[totalMinutes.size()-1] - totalMinutes[0]));
        return mini;
    }
};