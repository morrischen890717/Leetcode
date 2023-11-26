class Solution {
public:
    void solve(vector<int>& nums, vector<bool>& visited, vector<int>& cur, vector<vector<int>>& ans){
        if(cur.size() == nums.size()){
            ans.push_back(cur);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(visited[i])
                continue;
            visited[i] = true;
            cur.push_back(nums[i]);
            solve(nums, visited, cur, ans);
            cur.pop_back();
            visited[i] = false;
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<bool> visited(n, false);
        vector<int> cur;
        solve(nums, visited, cur, ans);
        return ans;      
    }
};