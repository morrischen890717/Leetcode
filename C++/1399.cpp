class Solution {
public:
    int countDigits(int num){
        int res = 0;
        while(num){
            res += num % 10;
            num /= 10;
        }
        return res;
    }
    int countLargestGroup(int n) {
        int size = 0, cnt = 0;
        unordered_map<int, int> m;
        for(int i = 1; i <= n; i++){
            int res = countDigits(i);
            m[res]++;
            if(m[res] == size)
                cnt++;
            else if(m[res] > size){
                size = m[res];
                cnt = 1;
            }
        }
        return cnt;
    }
};