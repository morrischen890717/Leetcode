class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        // using bottom-up DP
        // time complexity: O(M * N), space complexity: O(N), where M == matrix.size() and N == matrix[0].size()
        // reference: https://leetcode.com/problems/maximal-rectangle/solutions/29054/share-my-dp-solution/?envType=daily-question&envId=2024-04-13
        int ans = 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> height(n, 0), left(n, 0), right(n, n - 1);
        for(int i = 0; i < m; i++){
            int cur_left = 0, cur_right = n - 1;
            for(int j = 0; j < n; j++){
                height[j] = matrix[i][j] == '1' ? height[j] + 1 : 0;
            }
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '1')
                    left[j] = max(left[j], cur_left);
                else{
                    left[j] = 0;
                    cur_left = j + 1;
                }
            }
            for(int j = n - 1; j >= 0; j--){
                if(matrix[i][j] == '1')
                    right[j] = min(right[j], cur_right);
                else{
                    right[j] = n - 1;
                    cur_right = j - 1;
                }
            }
            for(int j = 0; j < n; j++){
                ans = max(ans, (right[j] - left[j] + 1) * height[j]);
            }
        }
        return ans;
    }
};