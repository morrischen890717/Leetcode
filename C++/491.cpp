class Solution {
public:
    void solve(vector<int>& nums, int n, int prev, int i, vector<int>& cur, vector<vector<int>>& res){
        if(i == n){
            if(cur.size() >= 2)
                res.push_back(cur);
            return;
        }
        if(nums[i] >= prev){
            cur.push_back(nums[i]);
            solve(nums, n, nums[i], i + 1, cur, res);
            cur.pop_back();
        }
        if(nums[i] != prev) // avoid duplicate answer
            solve(nums, n, prev, i + 1, cur, res);
        return;
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> cur;
        solve(nums, n, -1000, 0, cur, res);
        return res;
    }
};