class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        // using two-pointers and Greedy
        // time complexity: O(N), space complexity: O(1)
        int n = nums.size();
        int l = k, r = k;
        int ans = nums[k], min_num = nums[k];
        while(l - 1 >= 0 || r + 1 < n){
            int left = l - 1 >= 0 ? nums[l - 1] : -1, right = r + 1 < n ? nums[r + 1] : -1;
            if(left > right){
                min_num = min(min_num, left);
                l--;
            }
            else{
                min_num = min(min_num, right);
                r++;
            }
            int score = min_num * (r - l + 1);
            ans = max(ans, score);
        }
        return ans;
    }
};