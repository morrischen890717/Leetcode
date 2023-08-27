class Solution {
public:
    bool dfs(vector<vector<int>>& v, vector<int>& group, int g, int person){
        if(group[person] != -1)
            return group[person] == g;
        group[person] = g;
        for(int i = 0; i < v[person].size(); i++){
            if(!dfs(v, group, !g, v[person][i]))
                return false;
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        // using DFS
        // time complexity: O(N), space complexity: O(N^2)
        vector<vector<int>> v(n + 1);
        vector<int> group(n + 1, -1);
        for(vector<int>& dislike: dislikes){
            v[dislike[0]].push_back(dislike[1]);
            v[dislike[1]].push_back(dislike[0]);
        } 
        for(int i = 1; i <= n; i++){
            if(!dfs(v, group, 0, i) && !dfs(v, group, 1, i))
                return false;
        }
        return true;
    }
};