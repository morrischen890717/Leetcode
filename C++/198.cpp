class Solution {
public:
    int rob(vector<int>& nums) {
        // using bottom-up DP
        // time complexity: O(N), space complexity: O(1)
        int rob = 0, not_rob = 0;
        for(int num: nums){
            int tmp = rob;
            rob = not_rob + num;
            not_rob = max(not_rob, tmp);
        }
        return max(rob, not_rob);
    }
};