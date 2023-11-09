class Solution {
public:
    int countHomogenous(string s) {
        // time complexity: O(N), space complexity: O(1)
        const int MOD = 1e9 + 7;
        long long ans = 0;
        int cnt = 0;
        char prev = '.';
        for(char c: s){
            if(c != prev){
                cnt = 0;
                prev = c;
            }
            cnt++;
            ans += cnt;
            ans %= MOD;
        }
        return ans;
    }
};