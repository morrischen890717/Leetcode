class Solution {
public:
    string longestPalindrome(string s) {
        /*
        using two pointers
        time complexity: O(N^2)
        space complexity: O(1)
        */
        int len = s.length();
        pair<int, int> ans = {-1, 0}; // ans = {start_id, length}
        for(int i = 0; i < len; i++){
            pair<int, int> p1 = extend(s, len, i, i); // odd
            pair<int, int> p2 = extend(s, len, i, i + 1);
            if(p1.second > ans.second)
                ans = p1;
            if(p2.second > ans.second)
                ans = p2;
        }
        return s.substr(ans.first, ans.second);
    }
    pair<int, int> extend(string s, int len, int l, int r){
        while(l >= 0 && r < len && s[l] == s[r]){
            l--;
            r++;
        }
        l++;
        r--;
        return {l, r - l + 1};
    }
};