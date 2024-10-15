class Solution {
public:
    long long minimumSteps(string s) {
        long long swap = 0;
        int cnt_1 = 0;
        for(char c: s){
            if(c == '1')
                cnt_1++;
            else
                swap += cnt_1;
        }
        return swap;
    }
};