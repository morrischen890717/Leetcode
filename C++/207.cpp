class Solution {
public:
    bool loop(vector<vector<int>>& edges, int i, vector<bool>& visited){
        if(edges[i].size() == 0 || edges[i][0] == -1) 
            return false;
        if(visited[i])
            return true;
        visited[i] = true;
        for(int j = 0; j < edges[i].size(); j++){
            if(loop(edges, edges[i][j], visited))
                return true;
        }
        edges[i][0] = -1; // the node has been visited and there was no loop
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        /*
        using DFS
        Main idea: if there exists loop, then return false. Otherwise, return return true
        Time Complexity: O(numCourses + N), where N is the size of prerequisites
        */
        vector<bool> visited(numCourses, false);
        vector<vector<int>> edges(numCourses);
        for(vector<int> prerequisite: prerequisites){
            edges[prerequisite[0]].push_back(prerequisite[1]);
        }
        for(int i = 0; i < numCourses; i++){
            if(loop(edges, i, visited))
                return false;
        }
        return true;
    }
};