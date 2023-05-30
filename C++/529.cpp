class Solution {
public:
    int adjacentMines(vector<vector<char>>& board, vector<int>& dir, int m, int n, int i, int j){
        int cnt = 0;
        for(int k = 0; k < 8; k++){
            int new_i = i + dir[k], new_j = j + dir[k + 1];
            if(new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && (board[new_i][new_j] == 'M' || board[new_i][new_j] == 'X'))
                cnt++;
        }
        return cnt;
    }
    void dfs(vector<vector<char>>& board, vector<int>& dir, int m, int n, int i, int j){
        if(i < 0 || i >= m || j < 0 || j >= n || !(board[i][j] == 'M' || board[i][j] == 'E'))
            return;
        if(board[i][j] == 'M')
            board[i][j] = 'X';
        else if(board[i][j] == 'E'){
            int cnt = adjacentMines(board, dir, m, n, i, j);
            if(cnt == 0){
                board[i][j] = 'B';
                for(int k = 0; k < 8; k++){
                    dfs(board, dir, m, n, i + dir[k], j + dir[k + 1]);
                }
            }
            else
                board[i][j] = '0' + cnt;
        }
        return;
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m = board.size(), n = board[0].size();
        vector<int> dir = {-1, 0, 1, 0, -1, -1, 1, 1, -1};
        dfs(board, dir, m, n, click[0], click[1]);
        return board;
    }
};