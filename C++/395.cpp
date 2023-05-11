class Solution {
public:
    int longestSubstring(string s, int k) {
        /*
        using two-pointer, time complexity: O(26 * N) = O(N)
        reference:
        https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/solutions/87739/java-strict-o-n-two-pointer-solution/
        https://imgur.com/a/NyXsUZH
        */
        int ans = 0;
        int len = s.length();
        for(int diff_char = 1; diff_char <= 26; diff_char++){
            vector<int> cnt(26, 0);
            int i = 0;
            int cur_diff_char = 0;
            int no_less_than_k = 0;
            for(int j = 0; j < len; j++){
                int id = s[j] - 'a';
                if(cnt[id] == 0)
                    cur_diff_char++;
                cnt[id]++;
                if(cnt[id] == k)
                    no_less_than_k++;
                while(cur_diff_char > diff_char){
                    int remove_id = s[i] - 'a';
                    if(cnt[remove_id] == k)
                        no_less_than_k--;
                    cnt[remove_id]--;
                    if(cnt[remove_id] == 0)
                        cur_diff_char--;
                    i++;
                }
                if(cur_diff_char == diff_char && cur_diff_char == no_less_than_k){
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};