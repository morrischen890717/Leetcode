class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> ans;
        bool do_reverse = false;
        for(int base = 0; base < m; base++){
            int cnt = 0;
            int i = base, j = 0;
            while(i >= 0 && j < n){
                ans.push_back(mat[i][j]);
                cnt++;
                i--;
                j++;
            }
            if(do_reverse)
                reverse(ans.end() - cnt, ans.end());
            do_reverse = !do_reverse;
        }
        for(int base = 1; base < n; base++){
            int j = base, i = m - 1;
            int cnt = 0;
            while(i >= 0 && j < n){
                ans.push_back(mat[i][j]);
                cnt++;
                i--;
                j++;
            }
            if(do_reverse)
                reverse(ans.end() - cnt, ans.end());
            do_reverse = !do_reverse;
        }
        
        return ans;
    }
};