class Solution {
public:
    int rotatedDigits(int n) {
        int ans = 0;
        for(int i = 1; i <= n; i++){
            int num = i;
            bool valid = false;
            while(num){
                int digit = num % 10;
                if(digit == 3 || digit == 4 || digit == 7){
                    valid = false;
                    break;
                }
                else if(digit == 2 || digit == 5 || digit == 6 || digit == 9)
                    valid = true;
                num /= 10;
            }
            if(valid)
                ans++;
        }
        return ans;
    }
};