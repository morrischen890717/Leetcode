class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        int ans = 0;
        vector<pair<char, int>> cnt;
        int len = s.length();
        pair<char, int> cur = {s[0], 1};
        for(int i = 1; i < len; i++){
            if(s[i] == cur.first)
                cur.second++;
            else{
                cnt.push_back(cur);
                cur = {s[i], 1};
            }
        }
        cnt.push_back(cur);
        for(string& word: words){
            int ptrS = 0, ptrQ = 0;
            cur = {word[0], 1};
            bool stretchy = true;
            for(int i = 1; i < word.length() && ptrS < cnt.size(); i++){
                if(word[i] == cur.first)
                    cur.second++;
                else{
                    if(cur.first != cnt[ptrS].first || cur.second > cnt[ptrS].second || (cur.second !=  cnt[ptrS].second && cnt[ptrS].second < 3)){
                        stretchy = false;
                        break;
                    }
                    cur = {word[i], 1};
                    ptrS++;
                }
            }
            if(ptrS != cnt.size() - 1 || cur.first != cnt[ptrS].first || cur.second > cnt[ptrS].second || (cur.second !=  cnt[ptrS].second && cnt[ptrS].second < 3))
                stretchy = false;
            if(stretchy)
                ans++;
        }
        return ans;
    }
};