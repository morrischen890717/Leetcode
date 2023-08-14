class Solution {
public:
    string decodeAtIndex(string s, int k) {
        // time complexity: O(N), space complexity: O(1)
        // reference: https://leetcode.com/problems/decoded-string-at-index/solutions/156747/java-c-python-o-n-time-o-1-space/
        k--; // change 1-indexed to 0-indexed
        int len = s.length();
        long long cnt = 0;
        int i;
        for(i = 0; i < len && cnt <= k; i++){
            cnt = isdigit(s[i]) ? cnt * (s[i] - '0') : cnt + 1;
        }
        for(i--; i >= 0; i--){
            if(isdigit(s[i])){
                cnt /= (s[i] - '0');
                k %= cnt;
            }
            else{
                cnt--;
                if(cnt <= k)
                    return string(1, s[i]);
            }
        }
        return "-1";
    }
};