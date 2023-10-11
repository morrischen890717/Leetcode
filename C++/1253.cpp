class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        // using Greedy
        // time complexity: O(N), space complexity: O(N)
        int n = colsum.size();
        vector<vector<int>> ans(2, vector<int> (n));
        for(int i = 0; i < n; i++){
            if(colsum[i] == 2){
                upper--;
                lower--;
                ans[0][i] = ans[1][i] = 1;
            }
            else if(colsum[i] == 1){
                if(upper > lower){
                    upper--;
                    ans[0][i] = 1;
                    ans[1][i] = 0;
                }
                else{
                    lower--;
                    ans[0][i] = 0;
                    ans[1][i] = 1;
                }
            }
            else
                ans[0][i] = ans[1][i] = 0;
            if(upper < 0 || lower < 0)
                return {};
        }
        if(upper != 0 || lower != 0)
            return {};
        return ans;
    }
};