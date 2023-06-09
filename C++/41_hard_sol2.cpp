class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        /*
        time complexity: O(N), space complexity: O(1) (because we modify the original vector)
        Main Point: Put each number in its right place.
        */
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] < 0)
                continue;
            int next = nums[i] - 1;
            while(next >= 0 && next < n && nums[next] != next + 1){
                swap(nums[i], nums[next]);
                next = nums[i] - 1;
            }
        }
        for(int i = 0; i < n; i++){
            if(nums[i] != i + 1)
                return i + 1;
        }
        return n + 1;
    }
};