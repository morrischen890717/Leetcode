class Solution {
public:
    long long wonderfulSubstrings(string word) {
        // using bit manipulation, unordered_map, and prefix sum
        long long ans = 0;
        unordered_map<int, int> cnt;
        int state = 0;
        cnt[0] = 1;
        for(char c: word){
            state ^= (1 << (c - 'a'));
            if(cnt.count(state))
                ans += cnt[state];
            for(int i = 0; i < 10; i++){
                int tmp = state ^ (1 << i);
                if(cnt.count(tmp))
                    ans += cnt[tmp];
            }
            cnt[state]++;
        }
        return ans;
    }
};