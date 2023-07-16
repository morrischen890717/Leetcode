class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        int digitCnt = 0;
        int tmp = n;
        for(tmp = n; tmp; tmp /= 10){ // count the number of digits
            digitCnt++;
        }
        int prevDigit = -1;
        int prevId = -1; // prevId stands for the index of digit which is strictly smaller than current digit
        tmp = n;
        for(int i = digitCnt - 1; i >= 0; i--){
            int num = pow(10, i);
            int curDigit = tmp / num;
            if(curDigit < prevDigit){
                n /= pow(10, prevId);
                return n * pow(10, prevId) - 1;
            }
            else if(curDigit > prevDigit){
                prevDigit = curDigit;
                prevId = i;
            }
            tmp %= num;
        }
        return n;
    }
};