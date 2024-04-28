class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        // using priority_queue and bottom-up DP
        // time complexity: O(M * NlogN), space complexity: O(N), where M == grid.size() and N == grid[0].size()
        int m = grid.size(), n = grid[0].size();
        for(int i = 1; i < m; i++){
            priority_queue<int, vector<int>, greater<int>> pq(grid[i - 1].begin(), grid[i - 1].end());
            int first_smallest = pq.top();
            pq.pop();
            int second_smallest = pq.top();
            for(int j = 0; j < n; j++){
                grid[i][j] += grid[i - 1][j] == first_smallest ? second_smallest : first_smallest;
            }
        }
        int ans = INT_MAX;
        for(int j = 0; j < n; j++){
            ans = min(ans, grid[m - 1][j]);
        }
        return ans;
    }
};