class Solution {
public:
    void dfs(vector<vector<int>>& rooms, vector<bool>& keys, int& cnt, int cur){
        for(int key: rooms[cur]){
            if(keys[key] == false){
                keys[key] = true;
                cnt++;
                dfs(rooms, keys, cnt, key);
            }
        }
        return;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> keys(n, false);
        keys[0] = true;
        int cnt = 1;
        dfs(rooms, keys, cnt, 0);
        return cnt == n;
    }
};