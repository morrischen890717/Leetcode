class Solution {
public:
    int getSum(int a, int b) {
        // using math and bit manipulation
        // reference: https://leetcode.com/problems/sum-of-two-integers/solutions/132479/simple-explanation-on-how-to-arrive-at-the-solution/?envType=featured-list&envId=top-interview-questions%3FenvType%3Dfeatured-list&envId=top-interview-questions
        int carry = 0;
        while(b != 0){
            carry = (a & b);
            a ^= b;
            b = (carry << 1);
        }
        return a;
    }
};