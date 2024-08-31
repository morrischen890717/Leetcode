class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        // using Greedy
        // time complexity: O(M * N), space complexity: O(M * N), where M == rowSum.size() and N == colSum.size()
        // reference: https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/solutions/876845/java-c-python-easy-and-concise-with-prove/?envType=daily-question&envId=2024-07-20
        int m = rowSum.size(), n = colSum.size();
        vector<vector<int>> ans(m, vector<int> (n));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ans[i][j] = min(rowSum[i], colSum[j]);
                rowSum[i] -= ans[i][j];
                colSum[j] -= ans[i][j];
            }
        }
        return ans;
    }
};