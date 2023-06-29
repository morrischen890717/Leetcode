class Solution {
    class Cell {
    public:
        int i, j, state;
        Cell(int i, int j, int state){
            this->i = i;
            this->j = j;
            this->state = state;
        }
    };

public:
    void addKey(Cell* cell, int key){
        cell->state |= (1 << key);
        return;
    }
    bool hasKey(Cell* cell, int key){
        return cell->state & (1 << key);
    }
    bool getAllKeys(int key_num, int state){
        return state == (1 << key_num) - 1;
    }
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dirs = {-1, 0, 1, 0, -1};
        queue<Cell*> q;
        unordered_set<string> visited;
        int key_num = 0;
        int step = 0;
        int got = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '@'){
                    q.push(new Cell(i, j, 0));
                }
                else if(grid[i][j] >= 'a' && grid[i][j] <= 'f')
                    key_num++;
            }
        }

        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                Cell *cur = q.front();
                q.pop();
                char c = grid[cur->i][cur->j];
                if(c == '#' || (c >= 'A' && c <= 'F' && !hasKey(cur, c - 'A')))
                    continue;
                if(c >= 'a' && c <= 'f'){
                    addKey(cur, c - 'a');
                    if(getAllKeys(key_num, cur->state))
                        return step;
                }
                for(int j = 0; j < 4; j++){
                    int new_i = cur->i + dirs[j], new_j = cur->j + dirs[j + 1];
                    string s = to_string(new_i) + " " + to_string(new_j) + " " + to_string(cur->state);
                    if(new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && !visited.count(s)){
                        visited.insert(s);
                        q.push(new Cell(new_i, new_j, cur->state));
                    }
                }
            }
            step++;
        }
        return -1;
    }
};