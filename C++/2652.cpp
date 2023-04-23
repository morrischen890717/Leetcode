class Solution {
public:
    int arithmetic_series(int num, int cnt){
        return (2 * num + (cnt - 1) * num) * cnt / 2;
    }
    int sumOfMultiples(int n) {
        return arithmetic_series(3, n / 3) + arithmetic_series(5, n / 5) + arithmetic_series(7, n / 7) - arithmetic_series(15, n / 15) - arithmetic_series(21, n / 21) - arithmetic_series(35, n / 35) + arithmetic_series(105, n / 105);
    }
};