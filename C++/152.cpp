class Solution {
public:
    int maxProduct(vector<int>& nums) { // using Kadane's Algorithm
        int n = nums.size();
        int product = 1;
        int ans = INT_MIN;
        for(int i = 0; i < n; i++){
            product *= nums[i];
            if(ans < product) 
                ans = product;
            if(product == 0)
                product = 1;
        }
        product = 1;
        for(int i = n - 1; i >= 0; i--){  // avoid the situation like {-8,5,3,1,6}
            product *= nums[i];
            if(ans < product)
                ans = product;
            if(product == 0)
                product = 1;
        }
        return ans;
    }
};