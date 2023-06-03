class Solution {
public:
    void dfs(vector<vector<int>>& subordinates, vector<int>& informTime, int i, int sum, int& ans){
        if(informTime[i] == 0){
            ans = max(ans, sum);
            return;
        }
        sum += informTime[i];
        for(int subordinate: subordinates[i]){
            dfs(subordinates, informTime, subordinate, sum, ans);
        }
        return;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> subordinates(n);
        for(int i = 0; i < manager.size(); i++){
            if(manager[i] != -1)
                subordinates[manager[i]].push_back(i);
        }
        int ans = 0;
        dfs(subordinates, informTime, headID, 0, ans);
        return ans;
    }
};