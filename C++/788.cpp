class Solution {
public:
    bool check(int cur){ // check whether cur has only '0', '1', '8' or not
        int remainder = cur % 10;
        while(cur > 0 && (remainder == 0 || remainder == 1 || remainder == 8)){
            cur /= 10;
            remainder = cur % 10;
        }
        return cur == 0 ? false : true;
    }
    int dfs(int n, int digitsNum, vector<int>& valid, int cur, int pos){
        if(pos == digitsNum)
            return (check(cur) && cur <= n ? 1 : 0);
        int cnt = 0;
        for(int num: valid){
            cnt += dfs(n, digitsNum, valid, cur * 10 + num, pos + 1);
        }
        return cnt;
    }
    int rotatedDigits(int n) {
        vector<int> valid = {0, 1, 2, 5, 6, 8, 9};
        int digitsNum = 0; // # of digits
        int tmp = n;
        while(tmp){
            digitsNum++;
            tmp /= 10;
        }
        return dfs(n, digitsNum, valid, 0, 0);
    }
};