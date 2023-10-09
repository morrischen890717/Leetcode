class Solution {
public:
    int binary_search(vector<int>& nums, int l, int r, int target, int first_or_last){
        int pos;
        while(l <= r){
            pos = (l + r) / 2;
            if(nums[pos] < target)
                l = pos + 1;
            else if(nums[pos] > target)
                r = pos - 1;
            else if(!first_or_last){
                if(pos == 0 || (nums[pos - 1] < target))
                    return pos;
                else
                    r = pos - 1;
            }
            else if(first_or_last){
                if(pos == nums.size() - 1 || nums[pos + 1] > target)
                    return pos;
                else
                    l = pos + 1;
            }
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int first_pos, last_pos;
        first_pos = binary_search(nums, 0, nums.size() - 1, target, 0);
        last_pos = binary_search(nums, 0, nums.size() - 1, target, 1);
        ans.push_back(first_pos);
        ans.push_back(last_pos);
        return ans;
    }
};