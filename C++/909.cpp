class Solution {
public:
    pair<int, int> convertId(int n, int i){ // 0-indexed conversion, get its coordinate on the board
        int x = n - 1 - i / n, y;
        if((i / n) % 2)
            y = n - 1 - i % n;
        else
            y = i % n;
        return {x, y};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        // using BFS
        int n = board.size();
        vector<bool> visited(n * n + 1, false);
        queue<int> q;
        q.push(1);
        int move = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                int id = q.front();
                q.pop();
                if(visited[id])
                    continue;
                visited[id] = true;
                if(id == n * n)
                    return move;
                for(int j = 1; j <= 6 && id + j <= n * n; j++){
                    pair<int, int> p = convertId(n, id + j - 1); // -1 for changing to 0-indexed
                    int next = board[p.first][p.second] == -1 ? id + j : board[p.first][p.second];
                    q.push(next);
                }
            }
            move++;
        }
        return -1;
    }
};