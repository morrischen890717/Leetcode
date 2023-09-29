class Solution {
public:
    int maxRepOpt1(string text) {
        // time complexity: O(N)
        // reference: https://leetcode.com/problems/swap-for-longest-repeated-character-substring/solutions/355922/c-2-approaches/
        int ans = 1;
        int len = text.length();
        vector<vector<int>> pos(26);
        for(int i = 0; i < len; i++){
            pos[text[i] - 'a'].push_back(i);
        }
        for(int i = 0; i < 26; i++){
            int cnt = 1, cnt1 = 0, max_cnt = 0;
            for(int j = 1; j < pos[i].size(); j++){
                if(pos[i][j] == pos[i][j - 1] + 1)
                    cnt++;
                else{
                    cnt1 = pos[i][j] == pos[i][j - 1] + 2 ? cnt : 0;
                    cnt = 1;
                }
                max_cnt = max(max_cnt, cnt + cnt1);
            }
            ans = max(ans, max_cnt == pos[i].size() ? max_cnt : max_cnt + 1);
        }
        return ans;
    }
};