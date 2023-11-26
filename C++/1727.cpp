class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        // using sort
        // time complexity: O(M * N * logN), space complexity: O(N)
        // reference: https://leetcode.com/problems/largest-submatrix-with-rearrangements/solutions/1020710/c-clean-and-clear-with-intuitive-pictures-o-m-n-logn/?envType=daily-question&envId=2023-11-26
        int ans = 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> height(n, 0);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                height[j] = matrix[i][j] == 0 ? 0 : height[j] + 1;
            }
            vector<int> tmp(height.begin(), height.end());
            sort(tmp.begin(), tmp.end());
            for(int j = n - 1; j >= 0; j--){
                ans = max(ans, (n - j) * tmp[j]);
            }
        }
        return ans;
    }
};