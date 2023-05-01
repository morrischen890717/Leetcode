class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        /*
        time complexity: O(N), space complexity: O(1)
        reference: https://leetcode.com/problems/single-number-iii/solutions/68900/accepted-c-java-o-n-time-o-1-space-easy-solution-with-detail-explanations/
        */
        int n = nums.size();
        int diff = 0;
        for(int i = 0; i < n; i++){
            diff ^= nums[i];
        }
        // if answer is [a, b], then diff is the result of (a ^ b) now.
        // if bit_i in (a ^ b) is 1, bit_i at a and b are different.

        /*
        the following operation will only reserve the least significant bit     
        which is 1 in diff, and one of [a, b] is 1 at that bit, and the other 
        one of [a, b] is 0 at that bit (the bit at this position at a and b are different)
        */
        if(diff == INT_MIN)
            diff = 1;
        else
            diff &= ~(diff - 1); 

        vector<int> ans = {0, 0};
        for(int i = 0; i < n; i++){
            if((nums[i] & diff) == 0){
                ans[0] ^= nums[i];
            }
            else{
                ans[1] ^= nums[i];
            }
        }
        return ans;
    }
};