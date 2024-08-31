class Solution {
public:
    int findTheWinner(int n, int k) {
        // using math (this is a Josephus Problem)
        // time complexity: O(N), space complexity: O(1)
        // reference: https://leetcode.com/problems/find-the-winner-of-the-circular-game/solutions/1601186/c-3-approach-easy-understanding/?envType=daily-question&envId=2024-07-08
        //            https://cs.stackexchange.com/questions/7048/a-recursive-formula-for-generalized-josephus-problem
        int ans = 0;
        for(int i = 1; i <= n; i++){
            ans = (ans + k) % i;
        }
        return ans + 1;
    }
};