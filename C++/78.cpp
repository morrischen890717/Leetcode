class Solution {
public:
    void solve(vector<int>& nums, int i, vector<int>& cur, vector<vector<int>>& ans){
        if(i == nums.size()){
            ans.push_back(cur);
            return;
        }
        solve(nums, i + 1, cur, ans);
        cur.push_back(nums[i]);
        solve(nums, i + 1, cur, ans);
        cur.pop_back();
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        solve(nums, 0, cur, ans);
        return ans;
    }
};