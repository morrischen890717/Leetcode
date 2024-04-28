class Solution {
public:
    int tribonacci(int n) {
        vector<int> val = {0, 1, 1};
        for(int i = 3; i <= n; i++){
            val[i % 3] = val[0] + val[1] + val[2];
        }
        return val[n % 3];
    }
};