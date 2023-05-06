class Solution {
public:
    int getSum(int a, int b) {
        int ans = 0;
        int i = 0;
        int carry = 0;
        while((a || b || carry) && i < 32){ // i < 32 is for the situation of k+(-k)
            ans |= ((((a & 1) ^ (b & 1)) ^ carry) << i);
            carry = (((a & 1) & (b & 1)) | ((a & 1) & carry) | (carry & (b & 1)));
            a >>= 1;
            b >>= 1;
            i++;
        }
        return ans;
    }
};