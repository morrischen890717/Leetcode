class Solution {
public:
    bool solve(vector<int>& cur, int id, int n, int status){
        if(id == 2 * n - 1)
            return true;
        if(cur[id] != -1)
            return solve(cur, id + 1, n, status);
        for(int i = n; i > 0; i--){
            if((status & (1 << i)) == 0){
                if(i == 1){
                    cur[id] = i;
                    if(solve(cur, id + 1, n, status | (1 << i)))
                        return true;
                    else
                        cur[id] = -1; 
                }
                else if(id + i < 2 * n - 1 && cur[id + i] == -1){
                    cur[id] = cur[id + i] = i;
                    if(solve(cur, id + 1, n, status | (1 << i)))
                        return true;
                    else
                        cur[id] = cur[id + i] = -1;     
                }
            }
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        vector<int> cur(2 * n - 1, -1);
        solve(cur, 0, n, 0);
        return cur;
    }
};