class Solution {
public:
    int dfs(vector<vector<int>>& graph, vector<vector<int>>& isPrerequisite, int cur, int target){
        if(cur == target)
            return isPrerequisite[cur][cur] = 1;
        if(isPrerequisite[cur][target] != 0)
            return isPrerequisite[cur][target];
        for(int next: graph[cur]){
            if(dfs(graph, isPrerequisite, next, target) == 1)
                return isPrerequisite[cur][target] = 1;
        }
        return isPrerequisite[cur][target] = -1;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<bool> ans;
        vector<vector<int>> graph(numCourses);
        vector<vector<int>> isPrerequisite(numCourses, vector<int> (numCourses, 0));
        for(vector<int>& prerequisite: prerequisites){
            graph[prerequisite[0]].push_back(prerequisite[1]);
        }
        for(vector<int>& q: queries){
            ans.push_back(dfs(graph, isPrerequisite, q[0], q[1]) == 1);
        }
        return ans;
    }
};