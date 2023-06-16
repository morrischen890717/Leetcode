class Solution {
public:
    int divideAndConquer(vector<int>&nums, vector<vector<int>>& combination, int MOD){
        int n = nums.size();
        if(n <= 1)
            return 1;
        vector<int> left;
        vector<int> right;
        for(int i = 1; i < n; i++){
            if(nums[i] < nums[0])
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }
        int left_res = divideAndConquer(left, combination, MOD);
        int right_res = divideAndConquer(right, combination, MOD);
        
        /*
        combination[n - 1][left.size()] means that we will pick left.size() positions from (n-1) positions, and put the elements in left in these positions.
        As for the elements in right, we will put them in the rest positions.
        */
        return (long long)left_res * right_res % MOD * combination[n - 1][left.size()] % MOD;
    }
    int numOfWays(vector<int>& nums) {
        /*
        using divide-and-conquer with Pascal's triangle(pre-computed)
        time complexity: O(N^2)
        reference: https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/solutions/819369/c-just-using-recursion-very-clean-and-easy-to-understand-o-n-2/
        */
        int n = nums.size();
        int MOD = 1e9 + 7;
        vector<vector<int>> combination(n + 1, vector<int> (n + 1, 1)); // this is Pascal's triangle, combination[i][j] stands for  C(i, j)
        for(int i = 0; i <= n; i++){
            for(int j = 1; j < i; j++){
                combination[i][j] = (long long)(combination[i - 1][j - 1] + combination[i - 1][j]) % MOD;
            }
        }
        return divideAndConquer(nums, combination, MOD) - 1;
    }
};