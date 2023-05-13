class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            unordered_map<int, int> d;
            int x = points[i][0], y = points[i][1];
            for(int j = 0; j < n; j++){
                int x1 = points[j][0], y1 = points[j][1];
                int distance = (x1 - x) * (x1 - x) + (y1 - y) * (y1 - y);
                d[distance]++;
            }
            for(auto it = d.begin(); it != d.end(); it++){
                ans += (it->second * (it->second - 1));
            }
        }
        return ans;
    }
};