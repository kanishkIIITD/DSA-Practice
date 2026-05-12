class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        return (a[1] - a[0]) > (b[1] - b[0]);
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), cmp);
        int ini = 0, curr = 0;
        for(auto& task: tasks){
            int actual = task[0];
            int minimum = task[1];
            if(curr < minimum){
                int deff = minimum - curr;
                ini += deff;
                curr += deff;
            }
            curr -= actual;
        }
        return ini;
    }
};