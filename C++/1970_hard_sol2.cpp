class Solution {
public:
    int find(vector<int>& parent, int i){
        return parent[i] == i || parent[i] == -1 ? i : find(parent, parent[i]);
    }

    void uni(vector<int>& parent, int i, int j){
        int p1 = find(parent, i), p2 = find(parent, j);
        parent[p1] = p2;
        return;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        /*
        using Union Find
        reference: 
        https://leetcode.com/problems/last-day-where-you-can-still-cross/solutions/1404105/c-union-find-dummy-node-strategy/
        https://leetcode.com/problems/last-day-where-you-can-still-cross/solutions/1403930/python-union-find-solution-explained/
        */
        vector<int> parent(row * col + 2, -1);
        vector<vector<int>> grid(row, vector<int> (col, 1));
        vector<int> dirs = {-1, 0, 1, 0, -1};
        int top = row * col, bottom = row * col + 1; // dummy node
        parent[top] = top;
        parent[bottom] = bottom;
        for(int i = cells.size() - 1; i >= 0; i--){
            int x = cells[i][0] - 1, y = cells[i][1] - 1;
            grid[x][y] = 0;
            for(int j = 0; j < 4; j++){
                int new_x = x + dirs[j], new_y = y + dirs[j + 1];
                if(new_y >= 0 && new_y < col){
                    if(new_x == -1)
                        uni(parent, x * col + y, top);
                    else if(new_x == row)
                        uni(parent, x * col + y, bottom);
                    else if(new_x >= 0 && new_x < row && !grid[new_x][new_y])
                        uni(parent, x * col + y, new_x * col + new_y);
                }
            } 
            if(find(parent, top) == find(parent, bottom))
                return i;
        }
        return -1;
    }
};