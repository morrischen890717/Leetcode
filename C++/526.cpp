class Solution {
public:
    void solve(int n, vector<bool>& used, int i, int& cnt){
        if(i > n){
            cnt++;
            return;
        }
        for(int j = 1; j <= n; j++){
            if(!used[j] && (i % j == 0 || j % i == 0)){
                used[j] = true;
                solve(n, used, i + 1, cnt);
                used[j] = false;
            }
        }
        return;
    }
    int countArrangement(int n) {
        vector<bool> used(n + 1, false);
        int cnt = 0;
        solve(n, used, 1, cnt);
        return cnt;
    }
};