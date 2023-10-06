class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        // using math
        // reference: https://leetcode.com/problems/airplane-seat-assignment-probability/solutions/411905/it-s-not-obvious-to-me-at-all-foolproof-explanation-here-and-proof-for-why-it-s-1-2/
        return n == 1 ? 1.0 : 0.5;
    }
};