class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int dist = abs(target[0]) + abs(target[1]);
        for(vector<int>& ghost: ghosts){
            int x = abs(target[0] - ghost[0]), y = abs(target[1] - ghost[1]);
            if(x + y <= dist){
                return false;
            }
        }
        return true;
    }
};