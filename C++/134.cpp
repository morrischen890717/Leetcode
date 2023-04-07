class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int base = 0;
        int curr_diff = 0;
        int total_diff = 0;
        int diff;
        for(int i = 0; i < n; i++){
            diff = gas[i] - cost[i];
            total_diff += diff;
            curr_diff += diff;
            if(curr_diff < 0){
                base = i + 1;
                curr_diff = 0;
            }
        }
        return total_diff >= 0 ? base : -1;
    }
};