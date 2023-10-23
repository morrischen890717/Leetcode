class Solution {
public:
    bool isPowerOfFour(int n) {
        // using math
        // reference: https://leetcode.com/problems/power-of-four/solutions/80460/1-line-c-solution-without-confusing-bit-manipulations/?envType=daily-question&envId=2023-10-23
        return n > 0 && (n & (n - 1)) == 0 && (n - 1) % 3 == 0;
    }
};