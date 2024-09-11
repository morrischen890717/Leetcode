class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = 0;
        start ^= goal;
        while(start){
            if(start & 1)
                ans++;
            start >>= 1;
        }
        return ans;
    }
};