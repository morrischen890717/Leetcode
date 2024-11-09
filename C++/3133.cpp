class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans = x;
        int i = 0;
        n--;
        while(n){
            if(x % 2 == 0){
                ans |= (n % 2 ? ((long long)1 << i) : 0);
                n >>= 1;
            }
            x >>= 1;
            i++;
        }
        return ans;
    }
};