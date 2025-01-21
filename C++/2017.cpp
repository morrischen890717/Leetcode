class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        // using prefix sum
        // time complexity: O(N), space complexity: O(1), where N == grid[0].size()
        // reference: https://leetcode.com/problems/grid-game/solutions/1486340/c-java-python-robot1-minimize-topsum-and-bottomsum-of-robot-2-picture-explained/?envType=daily-question&envId=2025-01-21
        long long ans = LLONG_MAX;
        int n = grid[0].size();
        long long up = 0, down = 0;
        for(int j = 1; j < n; j++){
            up += grid[0][j];
        }
        for(int j = 1; j <= n; j++){
            down += j - 2 >= 0 ? grid[1][j - 2] : 0;
            ans = min(ans, max(up, down));
            up -= j < n ? grid[0][j] : 0;
        }
        return ans;
    }
};