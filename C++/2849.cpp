class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int diff_x = abs(sx - fx), diff_y = abs(sy - fy);
        return !(diff_x == 0 && diff_y == 0 && t == 1) && min(diff_x, diff_y) + abs(diff_x - diff_y) <= t;
    }
};