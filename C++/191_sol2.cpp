class Solution {
public:
    int hammingWeight(uint32_t n) {
        // reference: https://leetcode.com/problems/number-of-1-bits/solutions/55255/c-solution-n-n-1/?envType=daily-question&envId=2023-11-29
        int ans = 0;
        while(n){
            n &= (n - 1);
            ans++;
        }
        return ans;
    }
};