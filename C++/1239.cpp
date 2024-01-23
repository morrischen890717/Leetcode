class Solution {
public:
    void solve(vector<int>& v, int i, int cur, int& ans){
        if(i == v.size()){
            int len = 0;
            while(cur > 0){
                if(cur & 1)
                    len++;
                cur >>= 1;
            }
            ans = max(ans, len);
            return;
        }
        solve(v, i + 1, cur, ans);
        if((v[i] & cur) == 0)
            solve(v, i + 1, v[i] | cur, ans);
        return;
    }
    int maxLength(vector<string>& arr) {
        // using bit manipulation and Backtracking
        int ans = 0;
        int n = arr.size();
        vector<int> v(n, 0);
        for(int i = 0; i < n; i++){
            for(char c: arr[i]){
                if(v[i] & (1 << (c - 'a'))){
                    v[i] = -1;
                    break;
                }
                v[i] |= (1 << (c - 'a'));
            }
        }
        solve(v, 0, 0, ans);
        return ans;
    }
};