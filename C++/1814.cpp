class Solution {
public:
    int reverse_num(int num){
        int res = 0;
        while(num){
            int digit = num % 10;
            num /= 10;
            res *= 10;
            res += digit;
        }
        return res;
    }
    int countNicePairs(vector<int>& nums) {
        // using unordered_map
        const int MOD = 1e9 + 7;
        long long ans = 0;
        unordered_map<int, int> cnt;
        for(int num: nums){
            cnt[reverse_num(num) - num]++;
        }
        for(unordered_map<int, int>:: iterator it = cnt.begin(); it != cnt.end(); it++){
            ans += (long long)it->second * (it->second - 1) / 2;
            ans %= MOD;
        }
        return ans;
    }
};