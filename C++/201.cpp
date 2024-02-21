class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        // using bit manipulation
        int ans = 0;
        for(int i = 0; i < 32; i++){
            if(left == right && (left & 1))
                ans |= (1 << i);
            left >>= 1;
            right >>= 1;
        }
        return ans;
    }
};