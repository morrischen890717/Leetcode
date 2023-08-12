class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int ans = 0;
        int x = 0, y = 0;
        int dir = 0;
        vector<int> dirs = {0, 1, 0, -1, 0};
        set<pair<int, int>> s;
        for(vector<int>& obstacle: obstacles){
            s.insert({obstacle[0], obstacle[1]});
        }
        for(int command: commands){
            if(command == -1)
                dir = (dir + 1) % 4;
            else if(command == -2)
                dir = (dir - 1 + 4) % 4;
            else{
                for(int i = 0; i < command; i++){
                    if(s.count({x + dirs[dir], y + dirs[dir + 1]}))
                        break;
                    x += dirs[dir];
                    y += dirs[dir + 1];
                }
                ans = max(ans, x * x + y * y);
            }
        }
        return ans;
    }
};