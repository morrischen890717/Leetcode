class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i = 0; i < n; i++){
            int l1 = i - 1 >= 0 ? nums[i - 1] : INT_MIN, l2 = i - 2 >= 0 ? nums[i - 2] : INT_MIN, r = i == n - 1 ? INT_MAX : nums[i + 1];
            if(nums[i] < l1){
                /*
                if l1 <= r:
                    let nums[i] = l1
                else if l2 <= nums[i]:
                    let l1 = l2
                else if l2 > nums[i]:
                    impossible
                */
                if(l1 <= r)
                    nums[i] = l1;
                else if(l2 > nums[i])
                    return false;
                cnt++;
                if(cnt > 1)
                    return false;
            }
        }
        return true;
    }
};