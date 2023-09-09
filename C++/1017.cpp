class Solution {
public:
    string baseNeg2(int n) {
        // using math
        // time complexity: O(logN)
        // reference: https://leetcode.com/problems/convert-to-base-2/solutions/265507/java-c-python-2-lines-exactly-same-as-base-2/
        // main idea: https://imgur.com/8OKSmg2
        string ans;
        while(n){
            ans = to_string(n & 1) + ans;
            n = -(n >> 1);
        }
        return ans == "" ? "0" : ans;
    }
};