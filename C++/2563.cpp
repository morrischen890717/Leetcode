class Solution {
public:
    long long cntLess(vector<int>& nums, int upper){
        long long res = 0;
        int n = nums.size();
        for(int i = 0, j = n - 1; i < j; i++){
            while(i < j && nums[i] + nums[j] >= upper){
                j--;
            }
            if(i < j)
                res += j - i;
        }
        return res;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        // using sort and two-pointers
        // time complexity: O(NlogN), space complexity: O(1)
        sort(nums.begin(), nums.end());
        return cntLess(nums, upper + 1) - cntLess(nums, lower);
    }
};