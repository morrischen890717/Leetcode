class Solution {
public:
    int get_square_sum(vector<vector<int>>& prefix, int x1, int y1, int x2, int y2){
        return prefix[x2][y2] - prefix[x1 - 1][y2] - prefix[x2][y1 - 1] + prefix[x1 - 1][y1 - 1];
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        // using prefix sum
        // time complexity: O(M * N), space complexity: O(M * N)
        // reference: https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/solutions/451909/c-two-o-mn-solutions-prefixsum-slidingwindow-prefixsum-smart-enumeration/
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> prefix(m + 1, vector<int> (n + 1, 0));
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }
        int len = 0;
        // time complexity: O(M * N + min(M, N)) = O(M * N)
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                while(i + len <= m && j + len <= n && get_square_sum(prefix, i, j, i + len, j + len) <= threshold){
                    len++;
                }
            }
        }
        return len;
    }
};