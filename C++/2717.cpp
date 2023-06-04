class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int id1, idn;
        for(int i = 0; i < n; i++){
            if(nums[i] == 1)
                id1 = i;
            else if(nums[i] == n)
                idn = i;
        }
        if(id1 < idn)
            ans = id1 + (n - 1 - idn);
        else
            ans = n - 2 + (id1 - idn);
        return ans;
    }
};