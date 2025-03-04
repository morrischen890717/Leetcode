class Solution {
public:
    bool checkPowersOfThree(int n) {
        if(n == 0)
            return true;
        int num = 1;
        while(num * 3 <= n){
            num *= 3;
        }
        if(num * 2 <= n)
            return false;
        return checkPowersOfThree(n - num);
    }
};