class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        if(coordinates[1][0] - coordinates[0][0] == 0){ // vertical line
            for(int i = 2; i < n; i++){
                if(coordinates[i][0] - coordinates[i - 1][0] != 0)
                    return false;
            }
        }
        else{
            double slope = (double)(coordinates[1][1] - coordinates[0][1]) / (coordinates[1][0] - coordinates[0][0]);
            for(int i = 2; i < n; i++){
                if(coordinates[i][0] - coordinates[i - 1][0] == 0)
                    return false;
                double cur = (double)(coordinates[i][1] - coordinates[i - 1][1]) / (coordinates[i][0] - coordinates[i - 1][0]);
                if(cur != slope)
                    return false;
            }
        }
        return true;
    }
};