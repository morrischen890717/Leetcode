class Solution {
public:
    int jump(vector<int>& nums, int cur){
        int n = nums.size();
        return ((cur + nums[cur]) % n >= 0 ? (cur + nums[cur]) % n : (cur + nums[cur]) % n + n);
    }
    bool circularArrayLoop(vector<int>& nums) {
        /*
        using Floyd Cycle Detection Algorithm / Tortoise and Hare Algorithm
        time complexity: O(N)
        reference: https://leetcode.com/problems/circular-array-loop/solutions/94148/java-slow-fast-pointer-solution/
        */
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] == 0)
                continue;
            int slow = i, fast = jump(nums, i);
            while(nums[fast] * nums[i] > 0 && nums[jump(nums, fast)] * nums[i] > 0){
                if(slow == fast){
                    if(slow == jump(nums, slow)) // cycle length == 1
                        break;
                    return true;
                }
                slow = jump(nums, slow);
                fast = jump(nums, jump(nums, fast));
            }
            slow = i;
            while(nums[slow] * nums[i] > 0){
                nums[slow] = 0;
                slow = jump(nums, slow);
            }
        }
        return false;
    }
};