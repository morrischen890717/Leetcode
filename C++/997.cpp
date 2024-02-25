class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> cnt(n + 1, 0);
        for(vector<int>& t: trust){
            cnt[t[0]] = INT_MIN;
            cnt[t[1]]++;
        }
        for(int i = 1; i <= n; i++){
            if(cnt[i] == n - 1)
                return i;
        }
        return -1;
    }
};