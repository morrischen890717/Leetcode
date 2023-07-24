class Solution {
public:
    int getMask(int block, int row, int col){
        return (block | row) | col;
    }
    void addOrRemove(int& block, int& row, int& col, int k){
        block ^= (1 << k);
        row ^= (1 << k);
        col ^= (1 << k);
        return;
    }
    bool solve(vector<vector<char>>& board, vector<int>& block, vector<int>& row, vector<int>& col, int n, int id){
        if(id == n * n)
            return true;
        int i = id / n, j = id % n;
        int b = i / 3 * 3 + j / 3; // block id
        if(board[i][j] != '.')
            return solve(board, block, row, col, n, id + 1);
        int mask = getMask(block[b], row[i], col[j]);
        for(int k = 1; k <= n; k++){
            if(!(mask & (1 << k))){ // find which digit is still available
                board[i][j] = '0' + k;
                addOrRemove(block[b], row[i], col[j], k); // add
                if(solve(board, block, row, col, n, id + 1))
                    return true;
                board[i][j] = '.';
                addOrRemove(block[b], row[i], col[j], k); // remove
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        int n = board.size();
        vector<int> block(n, 0), row(n, 0), col(n, 0); // stores that which digits were used for i-th block/row/col
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] != '.'){
                    int b = i / 3 * 3 + j / 3; // block id
                    int k = board[i][j] - '0';
                    block[b] |= (1 << k);
                    row[i] |= (1 << k);
                    col[j] |= (1 << k);
                }
            }
        }
        solve(board, block, row, col, n, 0);
        return;
    }
};