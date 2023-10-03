class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        // using Kadane's Algorithm
        // time complexity: O(N)
        // reference: https://leetcode.com/problems/k-concatenation-maximum-sum/solutions/382885/short-and-concise-o-n-c-solution/
        int MOD = 1e9 + 7;
        int n = arr.size();
        int sum = 0, max_sum = 0;
        int arr_sum = 0;
        for(int i = 0; i < n * min(k, 2); i++){
            if(i < n)
                arr_sum += arr[i];
            sum = arr[i % n] + max(0, sum);
            max_sum = max(max_sum, sum);
        }
        int mid = (long long)(k - 2) * arr_sum % MOD;
        return max({0, max_sum, k <= 1 ? 0 : (max_sum + mid)}) % MOD;
    }
};