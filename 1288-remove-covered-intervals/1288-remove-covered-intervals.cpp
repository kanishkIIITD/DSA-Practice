class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[0] == b[0])
            return a[1] > b[1];
        return a[0] < b[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int remaining_intervals = 0;
        int max_end = 0;

        for (const auto& interval : intervals) {
            if (interval[1] > max_end) {
                remaining_intervals++;
                max_end = interval[1];
            }
        }

        return remaining_intervals;
    }
};