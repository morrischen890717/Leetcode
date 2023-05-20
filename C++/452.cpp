class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end());
        int cur_arrow = points[0][1];
        int ans = 1;
        for(int i = 1; i < n; i++){
            if(cur_arrow < points[i][0]){
                ans++;
                cur_arrow = points[i][1]; // new shot
            }
            else
                cur_arrow = min(cur_arrow, points[i][1]);
        }
        return ans;
    }
};