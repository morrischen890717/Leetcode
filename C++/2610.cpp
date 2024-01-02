class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        unordered_map<int, int> m;
        for(int num: nums){
            m[num]++;
            if(m[num] > ans.size())
                ans.push_back({num});
            else
                ans[m[num] - 1].push_back(num);
        }
        return ans;
    }
};