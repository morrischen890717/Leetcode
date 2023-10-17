class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // using Greedy
        // time complexity: O(N), space complexity: O(1)
        // reference: https://leetcode.com/problems/majority-element/solutions/51613/o-n-time-o-1-space-fastest-solution/?envType=featured-list&envId=top-interview-questions%3FenvType%3Dfeatured-list&envId=top-interview-questions
        int ans, cnt = 0;
        for(int num: nums){
            if(cnt == 0){
                cnt++;
                ans = num;
            }
            else if(num == ans)
                cnt++;
            else
                cnt--;
        }
        return ans;
    }
};