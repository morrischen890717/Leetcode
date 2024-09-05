class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size(), num = n + m;
        int sum = num * mean;
        for(int roll: rolls){
            sum -= roll;
        }
        if(sum >= n && sum <= 6 * n){
            vector<int> ans(n, 1);
            sum -= n;
            int i = 0;
            while(sum){
                int add = min(5, sum);
                ans[i] += add;
                sum -= add;
                i++;
            }
            return ans;
        }
        return {};
    }
};