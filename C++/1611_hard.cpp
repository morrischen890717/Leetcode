class Solution {
public:
    int minimumOneBitOperations(int n, int ans=0) {
        // using math
        // reference: https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/solutions/877798/java-c-python-3-solutions-with-prove-o-1-space/?envType=daily-question&envId=2023-11-30
        if(n == 0)
            return ans;
        int b = 1;
        while((b << 1) <= n){
            b = (b << 1);
        }
        return minimumOneBitOperations(n ^ b ^ (b >> 1), ans + b);
    }
};