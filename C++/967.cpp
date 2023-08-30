class Solution {
public:
    void dfs(int n, int k, int cur, int num, vector<int>& ans){
        if(cur == n){
            ans.push_back(num);
            return;
        }
        int last = num % 10;
        if(last + k < 10)
            dfs(n, k, cur + 1, num * 10 + last + k, ans);
        if(last - k >= 0 && k != 0) // k != 0 aims to avoid duplicate insertion to ans
            dfs(n, k, cur + 1, num * 10 + last - k, ans);
        return;
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        for(int i = 1; i < 10; i++){
            dfs(n, k, 1, i, ans);
        }
        return ans;
    }
};