class Solution {
private:
    const int MOD = 1e9 + 7;
public:
    vector<vector<int>> mat_mul(vector<vector<int>>& mat1, vector<vector<int>>& mat2){
        int m = mat1.size(), n = mat1[0].size();
        vector<vector<int>> res(m, vector<int> (n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    res[i][j] += ((long long)mat1[i][k] * mat2[k][j]) % MOD;
                    res[i][j] %= MOD;
                }
            }
        }
        return res;
    }
    vector<vector<int>> mat_pow(vector<vector<int>>& mat, int t){
        int n = mat.size();
        vector<vector<int>> res(n, vector<int> (n, 0));
        for(int i = 0; i < n; i++){
            res[i][i] = 1;
        }
        while(t){
            if(t & 1)
                res = mat_mul(res, mat);
            mat = mat_mul(mat, mat);
            t >>= 1;
        }
        return res;
    }
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        // reference: https://leetcode.com/problems/total-characters-in-string-after-transformations-ii/solutions/5972988/python-fast-pow-o-log-t/?envType=daily-question&envId=2025-05-14
        const int MOD = 1e9 + 7;
        int n = nums.size();
        int len = s.length();
        vector<vector<int>> mat(26, vector<int> (26, 0));
        for(int i = 0; i < n; i++){
            for(int j = 1; j <= nums[i]; j++){
                mat[i][(i + j) % 26] = 1;
            }
        }
        vector<vector<int>> m = mat_pow(mat, t);
        vector<vector<int>> cnt(1, vector<int> (26, 0));
        for(char c: s){
            cnt[0][c - 'a']++;
        }
        vector<vector<int>> res = mat_mul(cnt, m);
        int ans = 0;
        for(int i = 0; i < res[0].size(); i++){
            ans += res[0][i];
            ans %= MOD;
        }
        return ans;
    }
};