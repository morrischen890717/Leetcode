class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        ans.push_back(0);
        for(int i = 0; i < n; i++){
            vector<int> tmp(ans);
            for(int& num: tmp){
                num |= (1 << i);
            }
            ans.insert(ans.end(), tmp.rbegin(), tmp.rend());
        }
        return ans;
    }
};