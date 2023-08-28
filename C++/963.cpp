class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        // using unordered_map
        // reference: https://leetcode.com/problems/minimum-area-rectangle-ii/solutions/210786/c-with-picture-find-diagonals-o-n-n/
        double area = DBL_MAX;
        int n = points.size();
        unordered_map<string, vector<vector<int>>> m;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int center_x = points[i][0] + points[j][0], center_y = points[i][1] + points[j][1];
                string s = to_string(center_x) + "," + to_string(center_y);
                m[s].push_back({points[i][0], points[i][1], points[j][0], points[j][1]});
            }
        }
        for(unordered_map<string, vector<vector<int>>>::iterator it = m.begin(); it != m.end(); it++){
            for(int i = 0; i < it->second.size(); i++){
                for(int j = i + 1; j < it->second.size(); j++){
                    if((it->second[j][0] - it->second[i][0]) * (it->second[j][2] - it->second[i][0]) + (it->second[j][1] - it->second[i][1]) * (it->second[j][3] - it->second[i][1]) == 0)
                        area = min(area, sqrt((it->second[j][0] - it->second[i][0]) * (it->second[j][0] - it->second[i][0]) + (it->second[j][1] - it->second[i][1]) * (it->second[j][1] - it->second[i][1])) * sqrt((it->second[j][2] - it->second[i][0]) * (it->second[j][2] - it->second[i][0]) + (it->second[j][3] - it->second[i][1]) * (it->second[j][3] - it->second[i][1])));
                }
            }
        }
        return area == DBL_MAX ? 0 : area;
    }
};