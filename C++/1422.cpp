class Solution {
public:
    int maxScore(string s) {
        // reference: https://leetcode.com/problems/maximum-score-after-splitting-a-string/solutions/597716/java-5-liner-one-pass/?envType=daily-question&envId=2023-12-22
        int len = s.length();
        int res = INT_MIN;
        int zeros = 0, ones = 0;
        for(int i = 0; i < len; i++){
            zeros += s[i] == '0' ? 1 : 0;
            ones += s[i] == '1' ? 1 : 0;
            if(i != len - 1)
                res = max(res, zeros - ones);
        }
        return res + ones;
    }
};