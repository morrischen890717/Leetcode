class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> ans(2);
        vector<int> v = {a, b, c};
        sort(v.begin(), v.end());
        if(v[2] - v[0] == 2)
            ans[0] = 0;
        else if(v[1] - v[0] == 1 || v[1] - v[0] == 2 || v[2] - v[1] == 1 || v[2] - v[1] == 2)
            ans[0] = 1;
        else
            ans[0] = 2;
        ans[1] = (v[1] - v[0] - 1) + (v[2] - v[1] - 1);
        return ans;
    }
};