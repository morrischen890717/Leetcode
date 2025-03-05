class Solution {
public:
    long long coloredCells(int n) {
        return (long long)2 * (n - 1) * n + 1;
    }
};