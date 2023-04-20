class Solution {
public:
    void dfs(vector<vector<char>>& board, int m, int n, int r, int c){
        if(r < 0 || r >= m || c < 0 || c >= n || board[r][c] == 'A' || board[r][c] == 'X')
            return;
        board[r][c] = 'A';
        dfs(board, m, n, r + 1, c);
        dfs(board, m, n, r - 1, c);
        dfs(board, m, n, r, c + 1);
        dfs(board, m, n, r, c - 1);
        return;
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; i++){
            dfs(board, m, n, i, 0);
            dfs(board, m, n, i, n - 1);
        }
        for(int i = 0; i < n; i++){
            dfs(board, m, n, 0, i);
            dfs(board, m, n, m - 1, i);
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'A')
                    board[i][j] = 'O';
                else if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
        return;
    }
};