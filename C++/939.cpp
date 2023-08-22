class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        // using brute-force
        // reference: https://leetcode.com/problems/minimum-area-rectangle/solutions/407844/easy-to-understand-c-solution/
        int area = INT_MAX;
        int n = points.size();
        unordered_map<int, unordered_set<int>> m;
        for(int i = 0; i < n; i++){
            m[points[i][0]].insert(points[i][1]);
        }
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(points[i][0] == points[j][0] || points[i][1] == points[j][1])
                    continue;
                if(m[points[i][0]].count(points[j][1]) && m[points[j][0]].count(points[i][1]))
                    area = min(area, abs(points[i][0] - points[j][0]) * abs(points[i][1] - points[j][1]));
            }
        }
        return area == INT_MAX ? 0 : area;
    }
};