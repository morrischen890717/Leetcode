class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        /*
        time complexity: O(N), space complexity: O(1) (because we modify the original vector)
        nums[i] = i - 1 (e.g. nums[0] = 1, nums[1] = 2) if value i - 1 exists in the original vector,
        otherwise nums[i] will be a negative number
        we do not care about the value which > nums.size() because the answer must less than or equal to nums.size
        (because the vector can only stores nums.size() numbers at most, which means [1, 2, ..., nums.size()])
        */
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] < 0 || nums[i] == i + 1) // nums[i] = i + 1 means that nums[i] is already right
                continue;
            int cur = i;
            int next = nums[cur] - 1; // the position should nums[i] be in
            nums[cur] = -1;
            while(next >= 0 && next < n && nums[next] != next + 1){ // nums[next] == next + 1 means that nums[next] is already right
                cur = next;
                next = nums[cur] - 1;
                nums[cur] = cur + 1;
            }
        }
        for(int i = 0; i < n; i++){
            if(nums[i] != i + 1)
                return i + 1;
        }
        return n + 1;
    }
};