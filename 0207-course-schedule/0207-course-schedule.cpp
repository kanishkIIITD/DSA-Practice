class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);
        for(auto course: prerequisites){
            adj[course[1]].push_back(course[0]);
            indegree[course[0]]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        int count = 0;
        while(!q.empty()){
            int node = q.front(); q.pop();
            count++;
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
        }
        if(count == numCourses)
            return true;
        return false;
    }
};