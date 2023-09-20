class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // using sliding window and two-pointers
        // time complexity: O(N), space complexity: O(1)
        // main idea: https://imgur.com/9Z8nhih
        int n = nums.size();
        int sum = 0;
        for(int num: nums){
            sum += num;
        }
        int target = sum - x;
        int max_len = -1, i = 0;
        sum = 0;
        for(int j = 0; j < n; j++){
            sum += nums[j];
            while(i <= j && sum > target){
                sum -= nums[i];
                i++;
            }
            if(sum == target)
                max_len = max(max_len, j - i + 1);
        }
        return max_len == -1 ? -1 : n - max_len;
    }
};