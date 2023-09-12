class Solution {
public:
    int solve(vector<int>& nums, int firstLen, int secondLen){
        // firstLen is always before secondLen
        int ans = 0;
        int n = nums.size();
        vector<int> left(n + 1, 0), right(n + 1, 0); // left stores the sum with length == firstLen, while right stores the sum with length == secondLen
        int sumLeft = 0, sumRight = 0;
        for(int i = 0, j = n - 1; i < n; i++, j--){
            sumLeft += nums[i];
            sumRight += nums[j];
            left[i + 1] = max(left[i], sumLeft);
            right[j] = max(right[j + 1], sumRight);
            if(i + 1 >= firstLen){
                ans = max(ans, left[i + 1] + right[i + 1]);
                sumLeft -= nums[i - firstLen + 1];
            }
            if(i + 1 >= secondLen){
                ans = max(ans, left[j] + right[j]);
                sumRight -= nums[j + secondLen - 1];
            }
        }
        return ans;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        // using prefix sum
        // time complexity: O(N)
        int n = nums.size();
        return max(solve(nums, firstLen, secondLen), solve(nums, secondLen, firstLen));
    }
};