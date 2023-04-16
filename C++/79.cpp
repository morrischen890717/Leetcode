class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, vector<int>& dir, int i, int j, int id){
        if(id == word.length())
            return true;
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[id])
            return false;
        board[i][j] = '0';  // visited
        for(int k = 0; k < 4; k++){  // 4 directions
            if(dfs(board, word, dir, i + dir[k], j + dir[k + 1], id + 1))
                return true;
        }
        board[i][j] = word[id];  // restore to origin state
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        int l = word.length();
        unordered_map<char, int> cnt;
        vector<int> dir = {0, 1, 0, -1, 0};
        for(int i = 0; i < l; i++){
            cnt[word[i]]++;
        }
        /*
        Why search pruning improves a lot:
        For example, if our word is: word = "aaaaaaab" and our board is:
        board = 
            "a a a a a a a a"
            "a a a a a a a a"
            "a a a a a a a a"
            "a a a a a a a a"
            "a a a a b a a a"
        If we start searching from letter 'a' we will have lots of branches to check, however if we reverse word: word = word[::-1], then our word becomes word = "baaaaaaa" and in our board we have only one letter b, then we start checking only from one position on board where letter 'b' is located, therefore we will have less number of calculation.
        */
        if(cnt[word[0]] > cnt[word[l - 1]])  // search pruning (very useful, its make execution time from 1910ms(beats 5.1%) to 135ms(beats 98.14%))
            reverse(word.begin(), word.end());
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(dfs(board, word, dir, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};