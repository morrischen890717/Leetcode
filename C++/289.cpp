class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        // time complexity: O(m * n), space complexity: O(1)
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int cnt = 0;
                for(int k = -1; k <= 1; k++){
                    for(int s = -1; s <= 1; s++){
                        if(i + k < 0 || i + k >= m || j + s < 0 || j + s >= n || (k == 0 && s == 0))
                            continue;
                        if(board[i + k][j + s] == 1 || board[i + k][j + s] == -1)   // find old live
                            cnt++;
                    }
                }
                // -1: new die(old live), 2: new live(old die)
                if(board[i][j] && (cnt < 2 || cnt > 3))
                    board[i][j] = -1;
                else if(!board[i][j] && cnt == 3)
                    board[i][j] = 2;
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == -1)
                    board[i][j] = 0;
                else if(board[i][j] == 2)
                    board[i][j] = 1;
            }
        }
        
        return;
    }
};