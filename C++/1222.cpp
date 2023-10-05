class Solution {
public:
    int direction(int x1, int y1, int x2, int y2){
        if(x1 == x2)
            return y1 > y2 ? 0 : 4;
        else if(y1 == y2)
            return x1 > x2 ? 2 : 6;
        else if(x1 - x2 == y1 - y2)
            return x1 > x2 ? 1 : 5;
        else if(x1 - x2 == y2 - y1)
            return x1 > x2 ? 3 : 7;
        return 8; // cannot attack
    }
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> can_attack(8, {INT_MAX, INT_MAX});
        vector<vector<int>> ans;
        for(vector<int>& q: queens){
            int dir = direction(q[0], q[1], king[0], king[1]);
            int diff = max(abs(q[0] - king[0]), abs(q[1] - king[1]));
            if(dir != 8 && diff < max(abs(can_attack[dir][0] - king[0]), abs(can_attack[dir][1] - king[1])))
                can_attack[dir] = q;
        }
        for(vector<int>& v: can_attack){
            if(v[0] != INT_MAX)
                ans.push_back(v);
        }
        return ans;
    }
};