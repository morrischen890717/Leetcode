class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int ans = 0;
        int min_num = INT_MAX, max_num = INT_MIN;
        for(vector<int>& arr: arrays){
            int cur_min = INT_MAX, cur_max = INT_MIN;
            for(int& num: arr){
                cur_min = min(cur_min, num);
                cur_max = max(cur_max, num);
            }
            if(max_num != INT_MIN)
                ans = max({ans, max_num - cur_min, cur_max - min_num});
            max_num = max(max_num, cur_max);
            min_num = min(min_num, cur_min);
        }
        return ans;
    }
};