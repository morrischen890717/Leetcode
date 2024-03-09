class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnt(101, 0);
        int max_cnt = 0, max_cnt_num = 0;
        for(int num: nums){
            cnt[num]++;
        }
        for(int num: cnt){
            if(num == max_cnt)
                max_cnt_num++;
            else if(num > max_cnt){
                max_cnt = num;
                max_cnt_num = 1;
            }
        }
        return max_cnt * max_cnt_num;
    }
};