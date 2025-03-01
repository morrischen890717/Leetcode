class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        // using bottom-up DP
        int ans = 0;
        const int MOD = 1e9 + 7;
        int n = arr.size();
        int odd = 0, even = 0;
        for(int num: arr){
            if(num % 2){
                int tmp = odd;
                odd = even + 1;
                even = tmp;
            }
            else
                even += 1;
            odd %= MOD;
            even %= MOD;
            ans += odd;
            ans %= MOD;
        }
        return ans;
    }
};