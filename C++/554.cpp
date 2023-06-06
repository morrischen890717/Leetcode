class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        // the more edges on width i, the less bricks would be crossed on width i
        int n = wall.size();
        unordered_map<int, int> cnt;
        for(int i = 0; i < n; i++){
            int cur_edge = 0;
            for(int j = 0; j < wall[i].size(); j++){
                if(cur_edge > 0)
                    cnt[cur_edge]++;
                cur_edge += wall[i][j];
            }
        }
        int max_edge = 0;
        for(auto it = cnt.begin(); it != cnt.end(); it++){
            max_edge = max(max_edge, it->second);
        }
        return n - max_edge;
    }
};