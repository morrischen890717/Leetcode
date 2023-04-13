class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n == 1)
            return 1;
        int max_num = 0;
        for(int i = 0; i < n; i++){
            unordered_map<double, int> m;
            int self = 1;
            for(int j = i + 1; j < n; j++){
                if(points[i][0] == points[j][0] && points[i][1] == points[j][1])  // same point
                    self++;
                else if(points[i][0] == points[j][0])  // vertical line
                    m[INT_MAX]++;
                else{
                    double slope = double(points[i][1] - points[j][1]) / double(points[i][0] - points[j][0]);
                    m[slope]++;
                }
            }
            for(unordered_map<double, int>::iterator it = m.begin(); it != m.end(); it++){
                max_num = max(max_num, it->second + self);
            }
        }
        return max_num;
    }
};