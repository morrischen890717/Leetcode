class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // using bottom-up DP
        vector<vector<int>> ans = {{1}};
        for(int i = 1; i < numRows; i++){
            vector<int> v(i + 1);
            v[0] = 1;
            for(int j = 1; j < ans[i - 1].size(); j++){
                v[j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
            v[i] = 1;
            ans.push_back(v);
        }
        return ans;
    }
};