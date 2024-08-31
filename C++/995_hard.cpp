class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        // using sliding window
        // time complexity: O(N), space complexity: O(1)
        // reference: https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/solutions/238609/java-c-python-one-pass-and-o-1-space/?envType=daily-question&envId=2024-06-24
        int ans = 0;
        int n = nums.size();
        int flip_cnt = 0;
        for(int i = 0; i < n; i++){
            if(i >= k && nums[i - k] == 2)
                flip_cnt--;
            if((flip_cnt) % 2 == nums[i]){
                if(i + k > n)
                    return -1;
                nums[i] = 2;
                flip_cnt++;
                ans++;
            }
        }
        return ans;
    }
};