class Solution {
public:
    void recursion(vector<int>& candidates, int target, int index, vector<int>& curr_combine, vector<vector<int>>& ans){
        if(target == 0){
            ans.push_back(curr_combine);
            return;
        }
        int n = candidates.size();
        for(int i = index; i < n; i++){
            if(i != index && candidates[i] == candidates[i - 1])
                continue;
            if(candidates[i] > target)
                break;
            curr_combine.push_back(candidates[i]);
            recursion(candidates, target - candidates[i], i + 1, curr_combine, ans);
            curr_combine.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        vector<int> curr_combine;
        recursion(candidates, target, 0, curr_combine, ans);
        return ans;
    }
};