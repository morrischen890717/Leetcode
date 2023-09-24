class Solution {
public:
    int firstUniqChar(string s) {
        vector<pair<int, int>> cnt(26, {0, -1}); // {cnt, last position}
        for(int i = 0; i < s.length(); i++){
            cnt[s[i] - 'a'].first++;
            cnt[s[i] - 'a'].second = i;
        }
        int pos = INT_MAX;
        for(int i = 0; i < cnt.size(); i++){
            if(cnt[i].first == 1 && cnt[i].second < pos)
                pos = cnt[i].second;
        }
        return pos == INT_MAX ? -1 : pos;
    }
};