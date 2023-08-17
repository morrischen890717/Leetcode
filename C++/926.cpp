class Solution {
public:
    int minFlipsMonoIncr(string s) {
        // using DP
        // time complexity: O(N), space complexity: O(1)
        int cnt1 = 0, flip = 0;
        for(char c: s){
            if(c == '1')
                cnt1++;
            else
                flip = min(cnt1, flip + 1);
        }
        return flip;
    }
};