class Solution {
public:
    int distance(vector<int>& p1, vector<int>& p2){
        int x1 = p1[0], y1 = p1[1], x2 = p2[0], y2 = p2[1];
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> points = {p1, p2, p3, p4};
        unordered_map<int, bool> d;
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < i; j++){
                d[distance(points[i], points[j])] = true;
            }
        }
        return (d.size() == 2 && !d[0] ? true : false);
    }
};