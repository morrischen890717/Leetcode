class Solution {
public:
    int integerBreak(int n) {
        // using math
        // reference: https://leetcode.com/problems/integer-break/solutions/80689/a-simple-explanation-of-the-math-part-and-a-o-n-solution/
        int ans = 1;
        if(n == 2)
            return 1;
        if(n == 3)
            return 2;
        while(n > 4){
            ans *= 3;
            n -= 3;
        }
        ans *= n;
        return ans;
    }
};