class Solution {
public:
    int jump(vector<int>& nums, int cur){
        int n = nums.size();
        return (cur + nums[cur] + n) % n;
    }
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            nums[i] %= n;
        }
        for(int i = 0; i < n; i++){
            int sign = (nums[i] > 0 ? 1 : -1);
            int j = i;
            while(nums[j] < n && sign * nums[j] > 0){
                int next = jump(nums, j);
                nums[j] = i + n; // visited
                j = next;
                if(nums[j] == i + n){
                    // we have no need to check if the cycle length == 1 or not because we have done nums[i] %= n
                    return true;
                }
            }
        }
        return false;
    }
};