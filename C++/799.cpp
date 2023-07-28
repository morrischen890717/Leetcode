class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        // using bottom-up DP
        vector<double> prev;
        for(int i = 0; i <= query_row; i++){
            vector<double> cur(i + 1, 0.0);
            if(i == 0)
                cur[i] = (double)poured;
            for(int j = 0; j < i; j++){
                if(prev[j] > 1.0){ // excess champagne
                    cur[j] += (prev[j] - 1) / 2;
                    cur[j + 1] += (prev[j] - 1) / 2;
                }
            }
            prev = cur;
        }
        return prev[query_glass] > 1.0 ? 1.0 : prev[query_glass];
    }
};