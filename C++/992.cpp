class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // using sliding window (three pointers) and unordered_map
        // time complexity: O(N), space complexity: O(N)
        int ans = 0;
        int n = nums.size();
        unordered_map<int, int> pos; // pos[num] stands for the last appeared position of num
        int diff_cnt = 0; // # of different integers
        int l = 0, last = 0;
        for(int r = 0; r < n; r++){
            if(!pos.count(nums[r])){
                diff_cnt++;
                while(diff_cnt > k){
                    if(l == pos[nums[l]]){ // last one of nums[i]
                        diff_cnt--;
                        pos.erase(nums[l]);
                    }
                    l++;
                }
            }
            pos[nums[r]] = r;
            last = max(last, l);
            while(last != pos[nums[last]]){
                last++;
            }
            /*
            e.g. nums = [1, 2, 1, 2, 3], k = 2
            Now i = 3,
            l will be 0 (because the # of different integers is still 2)
            last will be 2, which is the last appearance id of the number 1, which is one of the different integers(1, 2)
            */
            if(diff_cnt == k)
                ans += (last - l + 1);
        }
        return ans;
    }
};