class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        /*
        using Greedy
        time complexity: O(N)
        */
        int n = nums.size();

        int max_num = INT_MIN;
        int right = -2; // index of the rightmost element in the answer subarray
        for(int i = 0; i < n; i++){ // find rightmost element
            if(nums[i] < max_num)
                right = i;
            else
                max_num = nums[i];
        }

        int min_num = INT_MAX;
        int left = -1; // index of the leftmost element in the answer subarray
        for(int i = n - 1; i >= 0; i--){ // find leftmost element
            if(nums[i] > min_num)
                left = i;
            else
                min_num = nums[i];
        }

        return right - left + 1;
    }
};