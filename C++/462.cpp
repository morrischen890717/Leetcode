class Solution {
public:
    int minMoves2(vector<int>& nums) {
        /*
        Time Complexity: O(N)
        reference:
        https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/solutions/2215782/visual-explanation-interview-tips-java/
        */
        int n = nums.size();
        int sum = 0;
        /*
        It does not matter whether the number of nums is odd or even
        Explanation: For even we can take any of the middle elements as median, no need to take their mean because for any number in the range of the 2 middle numbers the ans will be same.
        */
        nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
        int median = nums[n / 2];
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += abs(median - nums[i]);
        }
        return ans;
    }
};