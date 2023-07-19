class Solution {
public:
    string reorganizeString(string s) {
        string ans;
        vector<int> cnt(26, 0);
        priority_queue<pair<int, int>> pq; // {cnt, char}
        for(char c: s){
            cnt[c - 'a']++;
        }
        for(int i = 0; i < cnt.size(); i++){
            if(cnt[i])
                pq.push({cnt[i], i});
        }
        pair<int, int> prev = {-1, -1};
        for(int i = 0; i < s.length(); i++){
            if(pq.empty())
                return "";
            pair<int, int> cur = pq.top();
            pq.pop();
            ans += ('a' + cur.second);
            if(prev.first > 0)
                pq.push(prev);
            prev = cur;
            prev.first--;
        }
        return ans;
    }
};