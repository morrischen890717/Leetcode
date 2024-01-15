class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // using Kadane's Algorithm
        // time complexity: O(N), space complexity: O(1)
        // reference: https://leetcode.com/problems/maximum-product-subarray/solutions/183483/java-c-python-it-can-be-more-simple/
        int ans = INT_MIN;
        int n = nums.size();
        int product = 0;
        for(int i = 0; i < n; i++){
            if(product == 0)
                product = 1;
            product *= nums[i];
            ans = max(ans, product);
        }
        product = 1;
        for(int i = n - 1; i >= 0; i--){
            if(product == 0)
                product = 1;
            product *= nums[i];
            ans = max(ans, product);
        }
        return ans;
    }
};