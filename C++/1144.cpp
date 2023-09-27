class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        // using Greedy
        // time complexity: O(N), space complexity: O(1)
        // main idea: decrease odd-elements to fit the condition, or decrease even-elements to fit the condition
        int n = nums.size();
        int ans = INT_MAX;
        int decrease = 0;
        for(int i = 0; i < n; i += 2){
            int dist_left = i == 0 ? -1 : nums[i] - nums[i - 1];
            int dist_right = i == n - 1 ? -1 : nums[i] - nums[i + 1];
            int max_dist = max(dist_left, dist_right);
            if(max_dist >= 0)
                decrease += (max_dist + 1);
        }
        ans = min(ans, decrease);
        decrease = 0;
        for(int i = 1; i < n; i += 2){
            int dist_left = nums[i] - nums[i - 1];
            int dist_right = i == n - 1 ? -1 : nums[i] - nums[i + 1];
            int max_dist = max(dist_left, dist_right);
            if(max_dist >= 0)
                decrease += (max_dist + 1);
        }
        ans = min(ans, decrease);
        return ans;
    }
};