class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        // using unordered_map
        int ans = 0;
        int m = matrix.size(), n = matrix[0].size();
        unordered_map<string, int> cnt;
        for(int i = 0; i < m; i++){
            string same;
            int front = matrix[i][0];
            for(int j = 0; j < n; j++){
                same += matrix[i][j] == front ? '1' : '0';
            }
            cnt[same]++;
            ans = max(ans, cnt[same]);
        }
        return ans;
    }
};