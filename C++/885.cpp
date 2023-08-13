class Solution {
public:
    bool isInside(int rows, int cols, int rStart, int cStart){
        return rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols;
    }
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;
        vector<int> dirs = {0, 1, 0, -1, 0};
        int dir = 0, len = 1;
        ans.push_back({rStart, cStart});
        while(ans.size() < rows * cols){
            for(int i = 0; i < len; i++){
                rStart += dirs[dir];
                cStart += dirs[dir + 1];
                if(isInside(rows, cols, rStart, cStart))
                    ans.push_back({rStart, cStart});
            }
            dir = (dir + 1) % 4;
            for(int i = 0; i < len; i++){
                rStart += dirs[dir];
                cStart += dirs[dir + 1];
                if(isInside(rows, cols, rStart, cStart))
                    ans.push_back({rStart, cStart});
            }
            dir = (dir + 1) % 4;
            len++;
        }
        return ans;
    }
};