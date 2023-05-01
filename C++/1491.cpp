class Solution {
public:
    double average(vector<int>& salary) {
        int n = salary.size();
        int sum = 0;
        int max_val = INT_MIN, min_val = INT_MAX;
        for(int i = 0; i < n; i++){
            sum += salary[i];
            max_val = max(max_val, salary[i]);
            min_val = min(min_val, salary[i]);
        }
        sum -= max_val;
        sum -= min_val;
        return (double)sum / (n - 2);
    }
};