class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans(l.size(), true);
        for(int i = 0; i < l.size(); i++){
            vector<int> v(nums.begin() + l[i], nums.begin() + r[i] + 1);
            sort(v.begin(), v.end());
            int diff = v[1] - v[0];
            for(int j = 0; j < v.size() - 1; j++){
                if(v[j + 1] - v[j] != diff){
                    ans[i] = false;
                    break;
                }
            }
        }
        return ans;
    }
};