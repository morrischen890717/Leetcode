class Solution {
public:
    int largestVariance(string s) {
        /*
        using Kadane’s Algorithm
        reference: https://leetcode.com/problems/substring-with-largest-variance/solutions/2039178/weird-kadane/
        */
        int ans = 0;
        unordered_set<char> uniChar(s.begin(), s.end());
        for(char a: uniChar){
            for(char b: uniChar){
                bool has_b = false, first_is_b = false;
                int len = 0;
                for(char c: s){
                    if(c == a)
                        len++;
                    else if(c == b){
                        has_b = true;
                        if(first_is_b && len >= 0){
                            first_is_b = false;
                        }
                        else{
                            len--;
                            if(len < 0){
                                len = -1;
                                first_is_b = true;
                            }
                        }
                    }
                    ans = max(ans, has_b ? len : 0);
                }
            }
        }
        return ans;
    }
};