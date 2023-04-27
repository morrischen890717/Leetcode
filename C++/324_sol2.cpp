class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(nums);
        sort(v.begin(), v.end());
        reverse(v.begin(), v.begin() + n / 2 + n % 2);
        reverse(v.begin() + n / 2 + n % 2, v.end());
        for(int i = 0; i < n; i++){
            if(i % 2)
                nums[i] = v[n / 2 + n % 2 + i / 2];
            else
                nums[i] = v[i / 2];
        }
        return;
    }
};