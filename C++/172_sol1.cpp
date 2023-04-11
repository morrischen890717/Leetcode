class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        for(int d = 5; n / d > 0; d *= 5){
            ans += n / d;
        }
        return ans;
    }
};