class Solution {
public:
    void move(vector<int>& dirs, char c, int& x, int& y){
        int dir = -1;
        if(c == 'N')
            dir = 2;
        else if(c == 'S')
            dir = 0;
        else if(c == 'E')
            dir = 3;
        else
            dir = 1;
        x += dirs[dir];
        y += dirs[dir + 1];
        return;
    }
    bool isPathCrossing(string path) {
        unordered_set<string> s;
        vector<int> dirs = {1, 0, -1, 0, 1};
        int x = 0, y = 0;
        string ss = to_string(x) + "," + to_string(y);
        s.insert(ss);
        for(char c: path){
            move(dirs, c, x, y);
            ss = to_string(x) + "," + to_string(y);
            if(s.count(ss))
                return true;
            s.insert(ss);
        }
        return false;
    }
};