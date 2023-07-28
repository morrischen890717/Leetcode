class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        vector<pair<int, int>> cnt(8, {0, 0}); // {# of 'O', # of 'X'}
        int cntO = 0, cntX = 0;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                cntO += board[i][j] == 'O' ? 1 : 0;
                cntX += board[i][j] == 'X' ? 1 : 0;
                cnt[i].first += board[i][j] == 'O' ? 1 : 0;
                cnt[i].second += board[i][j] == 'X' ? 1 : 0;
                cnt[j + 3].first += board[i][j] == 'O' ? 1 : 0;
                cnt[j + 3].second += board[i][j] == 'X' ? 1 : 0;
                if(i == j){ // diagonal: upper-left to lower-right  
                    cnt[6].first += board[i][j] == 'O' ? 1 : 0;
                    cnt[6].second += board[i][j] == 'X' ? 1 : 0;
                }
                if(i + j == 2){ // diagonal: upper-right to lower-left
                    cnt[7].first += board[i][j] == 'O' ? 1 : 0;
                    cnt[7].second += board[i][j] == 'X' ? 1 : 0;
                }
            }
        }
        bool lineO = false, lineX = false;
        for(pair<int, int> p: cnt){
            if(p.first == 3)
                lineO = true;
            else if(p.second == 3)
                lineX = true;
        }
        if((lineO && lineX) || (lineO && cntX != cntO) || (lineX && cntX != cntO + 1))
            return false;
        return cntX == cntO || cntX == cntO + 1;
    }
};