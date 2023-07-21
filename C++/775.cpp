class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        /*
        using math
        time complexity: O(N), space complexity: O(1)
        reference: https://leetcode.com/problems/global-and-local-inversions/solutions/113644/c-java-python-easy-and-concise-solution/
        */
        int n = nums.size();
        int maxNum = INT_MIN;
        for(int i = 0; i < n - 1; i++){
            if(maxNum > nums[i + 1])
                return false;
            maxNum = max(maxNum, nums[i]);
        }
        return true;
    }
};