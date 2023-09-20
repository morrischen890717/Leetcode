class Solution {
public:
    int dfs(vector<int>& cnt){
        int res = 1;
        for(int i = 0; i < cnt.size(); i++){
            if(cnt[i] == 0)
                continue;
            cnt[i]--;
            res += dfs(cnt);
            cnt[i]++;
        }
        return res;
    }
    int numTilePossibilities(string tiles) {
        // using DFS
        vector<int> cnt(26, 0);
        for(char c: tiles){
            cnt[c - 'A']++;
        }
        return dfs(cnt) - 1; // -1 is for empty string
    }
};