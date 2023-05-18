class Solution {
public:
    void checkUpAndLeft(vector<vector<char>>& board, int i, int j, int& cnt){
        if((i - 1 >= 0 && board[i - 1][j] == 'X') || (j - 1 >= 0 && board[i][j - 1] == 'X'))
            return;
        cnt++;
        return;
    }
    int countBattleships(vector<vector<char>>& board) {
        // using only O(1) extra memory and without modifying the values in board
        int m = board.size(), n = board[0].size();
        int cnt = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'X'){
                    checkUpAndLeft(board, i, j, cnt);
                }
            }
        }
        return cnt;
    }
};