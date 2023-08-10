class Solution {
public:
    int counter(int n){
        int res = 0;
        while(n){
            res += pow(10, n % 10);
            n /= 10;
        }
        return res;
    }
    bool reorderedPowerOf2(int n) {
        int cnt = counter(n);
        for(int i = 0; i < 31; i++){
            if(counter(1 << i) == cnt)
                return true;
        }
        return false;
    }
};