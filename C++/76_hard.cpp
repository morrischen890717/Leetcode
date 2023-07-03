class Solution {
public:
    string minWindow(string s, string t) {
        /*
        using two-pointers
        reference: https://leetcode.com/problems/minimum-window-substring/solutions/26808/here-is-a-10-line-template-that-can-solve-most-substring-problems/
        */
        pair<int, int> ans = {-1, INT_MAX}; // {head, len}
        int len = s.length();
        int counter = t.length();
        vector<int> cnt(128, 0);
        for(char c: t){
            cnt[c]++;
        }
        int begin = 0, end = 0;
        while(end < len){
            cnt[s[end]]--;
            if(cnt[s[end]] >= 0)
                counter--;
            while(counter == 0){ // valid
                if(end - begin + 1 < ans.second){ // update
                    ans.first = begin; // ans.first stands for head
                    ans.second = end - begin + 1; // ans.second stands for length
                }
                cnt[s[begin]]++;
                if(cnt[s[begin]] > 0)
                    counter++;
                begin++;
            }
            end++;
        }
        return ans.first == -1 ? "" : s.substr(ans.first, ans.second);
    }
};