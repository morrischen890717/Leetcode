class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        /*
        using Floyd Cycle Detection Algorithm(Tortoise and Hare Algorithm)
        time complexity: O(N), space complexity: O(1)
        reference: 
        https://englishandcoding.pixnet.net/blog/post/30106939-leetcode-%E7%AD%86%E8%A8%98%EF%BC%8D287.-find-the-duplicate-number
        https://leetcode.com/problems/linked-list-cycle-ii/submissions/942571865/
        */
        int n = nums.size();
        int fast = 0, slow = 0;
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        slow = 0;
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};