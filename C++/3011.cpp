class Solution {
public:
    int cnt(int num){
        int res = 0;
        while(num){
            if(num % 2)
                res++;
            num /= 2;
        }
        return res;
    }

    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        int prev_cnt = 0;
        int prev_max = INT_MIN;
        int cur_max = INT_MIN, cur_min = INT_MAX;
        for(int num: nums){
            int cur_cnt = cnt(num);
            if(cur_cnt == prev_cnt){
                cur_max = max(cur_max, num);
                cur_min = min(cur_min, num);
            }
            else if(cur_min < prev_max)
                return false;
            else{
                prev_max = cur_max;
                cur_max = cur_min = num;
                prev_cnt = cur_cnt;
            }
        }
        return cur_min >= prev_max;
    }
};