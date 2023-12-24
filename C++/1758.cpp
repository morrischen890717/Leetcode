class Solution {
public:
    int minOperations(string s) {
        int last_0 = 0, last_1 = 0;
        for(char c: s){
            int tmp_0 = last_0, tmp_1 = last_1;
            if(c == '0'){
                tmp_0 = last_1;
                tmp_1 = last_0 + 1;
            }
            else{
                tmp_0 = last_1 + 1;
                tmp_1 = last_0;
            }
            last_0 = tmp_0;
            last_1 = tmp_1;
        }
        return min(last_0, last_1);
    }
};