class Solution {
public:
    bool judgeSquareSum(int c) {
        // using two pointers
        int l = 0, r = sqrt(c);
        while(l <= r){
            long long val = (long long)l * l + r * r;
            if(val == c)
                return true;
            else if(val < c)
                l++;
            else
                r--;
        }
        return false;
    }
};