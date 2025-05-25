class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> v(n + 1, 0);
        for(vector<int>& q: queries){
            v[q[0]]++;
            v[q[1] + 1]--;
        }
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += v[i];
            if(nums[i] > sum)
                return false;
        }
        return true;
    }
};