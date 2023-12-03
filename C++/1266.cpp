class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        int n = points.size();
        for(int i = 1; i < n; i++){
            int diff_x = abs(points[i][1] - points[i - 1][1]), diff_y = abs(points[i][0] - points[i - 1][0]);
            ans += max(diff_x, diff_y);
        }
        return ans;
    }
};