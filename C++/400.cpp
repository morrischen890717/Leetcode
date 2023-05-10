class Solution {
public:
    int findNthDigit(int n) {
        long long cnt = 9; // count of digits
        int digit = 1;
        while(cnt * digit < n){
            n -= cnt * digit;
            cnt *= 10;
            digit++;
        }
        int base = pow(10, digit - 1);
        int number = base + (n - 1) / digit; // move to the target integer
        number /= pow(10, (digit - 1) - ((n - 1) % digit)); // remove all digits in number after the answer digit
        number %= 10; // remove all digits in number before the answer digit(get the least significant digit)
        return number;
    }
};