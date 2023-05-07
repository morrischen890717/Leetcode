class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> nums(n, 0);
        vector<int> ans;
        for(int i = 0; i < queries.size(); i++){
            int tmp = (i == 0 ? 0 : ans[i - 1]);
            if(nums[queries[i][0]] != 0){
                if(queries[i][0] - 1 >= 0 && nums[queries[i][0]] == nums[queries[i][0] - 1])
                    tmp--;
                if(queries[i][0] + 1 < n && nums[queries[i][0]] == nums[queries[i][0] + 1])
                    tmp--;
            }
            nums[queries[i][0]] = queries[i][1];
            if(nums[queries[i][0]] != 0){
                if(queries[i][0] - 1 >= 0 && nums[queries[i][0]] == nums[queries[i][0] - 1])
                    tmp++;
                if(queries[i][0] + 1 < n && nums[queries[i][0]] == nums[queries[i][0] + 1])
                    tmp++;
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};