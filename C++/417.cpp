class Solution {
public:
    void dfs(vector<vector<int>>& heights, vector<vector<int>>& canReach, int ocean, int r, int c, int m, int n, vector<vector<int>>& ans){
        // argument ocean = 1 represents Pacific Ocean, ocean = 2 represents Atlantic Ocean
        if(canReach[r][c] & ocean)
            return;
        canReach[r][c] |= ocean;
        if(canReach[r][c] == 3) // 3(decimal) = 11(binary), represents both Pacific Ocean(01) and Atlantic Ocean(10)
            ans.push_back({r, c});
        if(r + 1 < m && heights[r + 1][c] >= heights[r][c])
            dfs(heights, canReach, ocean, r + 1, c, m, n, ans);
        if(r - 1 >= 0 && heights[r - 1][c] >= heights[r][c])
            dfs(heights, canReach, ocean, r - 1, c, m, n, ans);
        if(c + 1 < n && heights[r][c + 1] >= heights[r][c])
            dfs(heights, canReach, ocean, r, c + 1, m, n, ans);
        if(c - 1 >= 0 && heights[r][c - 1] >= heights[r][c])
            dfs(heights, canReach, ocean, r, c - 1, m, n, ans);   
        return;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> ans;
        vector<vector<int>> canReach(m, vector<int> (n, 0));
        for(int i = 0; i < n; i++){
            dfs(heights, canReach, 1, 0, i, m, n, ans); // Pacific Ocean
            dfs(heights, canReach, 2, m - 1, i, m, n, ans); // Atlantic Ocean
        }
        for(int i = 0; i < m; i++){
            dfs(heights, canReach, 1, i, 0, m, n, ans); // Pacific Ocean
            dfs(heights, canReach, 2, i, n - 1, m, n, ans); // Atlantic Ocean
        }
        return ans;
    }
};