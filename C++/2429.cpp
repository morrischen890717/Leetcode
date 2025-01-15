class Solution {
public:
    int minimizeXor(int num1, int num2){
        int ans = num1;
        int cnt1 = 0, cnt2 = 0;
        while(num1){
            if(num1 & 1)
                cnt1++;
            num1 >>= 1;
        }
        while(num2){
            if(num2 & 1)
                cnt2++;
            num2 >>= 1;
        }
        int i = 0;
        while(cnt1 != cnt2){
            if(cnt1 < cnt2 && (ans & (1 << i)) == 0){
                ans ^= (1 << i);
                cnt1++;
            }
            else if(cnt1 > cnt2 && ans & (1 << i)){
                ans ^= (1 << i);
                cnt1--;
            }
            i++;
        }
        return ans;
    }
};