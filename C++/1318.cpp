class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt = 0;
        for(int i = 0; i < 32; i++){
            int cur_a = a & 1, cur_b = b & 1, cur_c = c & 1;
            if(cur_c){
                if(!cur_a && !cur_b)
                    cnt++;
            }
            else{
                if(cur_a)
                    cnt++;
                if(cur_b)
                    cnt++;
            }
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return cnt;
    }
};