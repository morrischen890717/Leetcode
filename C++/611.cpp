class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        /*
        using three pointers
        time complexity: O(N^2)
        reference: https://leetcode.com/problems/valid-triangle-number/solutions/128135/a-similar-o-n-2-solution-to-3-sum/
        */
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int k = n - 1; k >= 2; k--){
            int i = 0, j = k - 1;
            while(i < j){
                if(nums[i] + nums[j] > nums[k]){
                    ans += (j - i);
                    j--;
                }
                else
                    i++;
            }
        }
        return ans;
    }
};