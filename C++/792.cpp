class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        // reference: https://leetcode.com/problems/number-of-matching-subsequences/solutions/117634/efficient-and-simple-go-through-words-in-parallel-with-explanation/
        int n = words.size();
        int ans = 0;
        vector<vector<pair<int, int>>> waiting(26); // {i, j} means that words[i] is waiting for j-th letter
        for(int i = 0; i < n; i++){
            waiting[words[i][0] - 'a'].push_back({i, 1});
        }
        for(char c: s){
            vector<pair<int, int>> tmp(waiting[c - 'a']);
            waiting[c - 'a'].clear();
            for(pair<int, int>& p: tmp){
                if(p.second == words[p.first].length())
                    ans++;
                else
                    waiting[words[p.first][p.second] - 'a'].push_back({p.first, p.second + 1});
            }
        }
        return ans;
    }
};