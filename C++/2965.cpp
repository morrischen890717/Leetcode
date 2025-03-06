class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> appeared(n * n + 1, 0);
        int twice = -1, missing = -1;
        for(vector<int>& v: grid){
            for(int num: v){
                appeared[num]++;
            }
        }
        for(int i = 1; i <= n * n; i++){
            if(appeared[i] == 2)
                twice = i;
            else if(appeared[i] == 0)
                missing = i;
        }
        return {twice, missing};
    }
};