class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans;
        int cnt = 0;
        char prev = '.';
        priority_queue<pair<int, char>> pq;
        if(a)
            pq.push({a, 'a'});
        if(b)
            pq.push({b, 'b'});
        if(c)
            pq.push({c, 'c'});
        while(!pq.empty()){
            pair<int, char> p = pq.top();
            pq.pop();
            if(prev == p.second){
                if(cnt >= 2){
                    if(pq.empty())
                        return ans;
                    pair<int, char> tmp = p;
                    p = pq.top();
                    prev = p.second;
                    pq.pop();
                    cnt = 0;
                    pq.push(tmp);
                }
                cnt++;
                p.first--;
                ans += p.second;
            }
            else{
                cnt = 1;
                prev = p.second;
                p.first--;
                ans += p.second;
            }
            if(p.first > 0)
                pq.push(p);
        }
        return ans;
    }
};