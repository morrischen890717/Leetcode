class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        // using math
        // reference: https://leetcode.com/problems/magic-squares-in-grid/solutions/133874/python-5-and-43816729/
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        vector<int> order = {4, 9, 2, 7, 6, 1, 8, 3};
        vector<pair<int, int>> path = {{-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}};
        for(int i = 1; i < m - 1; i++){
            for(int j = 1; j < n - 1; j++){
                if(grid[i][j] != 5 || grid[i - 1][j - 1] % 2)
                    continue;
                bool valid = true, validAnti = true; // valid stands for clockwise, validAnti stands for anticlockwise
                int id = find(order.begin(), order.end(), grid[i - 1][j - 1]) - order.begin();
                for(pair<int, int> next: path){
                    if(grid[i + next.first][j + next.second] != order[id % order.size()]){
                        validAnti = false;
                        break;
                    }
                    id++;
                }
                id = find(order.begin(), order.end(), grid[i - 1][j]) - order.begin();
                for(int k = path.size() - 1; k >= 0; k--){
                    pair<int, int> next = path[k];
                    if(grid[i + next.first][j + next.second] != order[id % order.size()]){
                        valid = false;
                        break;
                    }
                    id++;
                }
                if(valid || validAnti)
                    ans++;
            }
        }
        return ans;
    }
};