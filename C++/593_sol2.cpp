class Solution {
public:
    int distance(vector<int>& p1, vector<int>& p2){
        int x1 = p1[0], y1 = p1[1], x2 = p2[0], y2 = p2[1];
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> d(4, vector<int> (4, 0));
        vector<vector<int>> points = {p1, p2, p3, p4};
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < i; j++){
                d[i][j] = d[j][i] = distance(points[i], points[j]);
                if(d[i][j] == 0)
                    return false;
            }
        }
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                if(j == i)
                    continue;
                for(int k = 0; k < 4; k++){
                    if(k == i || k == j)
                        continue;
                    for(int t = 0; t < 4; t++){
                        if(t == i || t == j || t == k)
                            continue;
                        if(d[i][j] == d[j][k] && d[j][k] == d[k][t] && d[k][t] == d[t][i] && d[i][k] == d[j][t])
                            return true;
                    }
                }
            }
        }
        return false;
    }
};