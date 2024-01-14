class Solution {
public:
    int maximumGap(vector<int>& nums) {
        // using bucket sort
        // time complexity: O(N), space complexity: O(N)
        // reference: https://leetcode.com/problems/maximum-gap/solutions/50643/bucket-sort-java-solution-with-explanation-o-n-time-and-space/
        int n = nums.size();
        if(n == 1)
            return 0;
        int max_num = INT_MIN, min_num = INT_MAX;
        for(int num: nums){
            max_num = max(max_num, num);
            min_num = min(min_num, num);
        }
        int max_diff = max_num - min_num;
        int gap = max_diff / (n - 1) + (max_diff % (n - 1) ? 1 : 0);
        vector<pair<int, int>> bucket(n - 1, {INT_MAX, INT_MIN}); // {min in the bucket, max in the bucket}
        for(int num: nums){
            if(num == min_num || num == max_num)
                continue;
            int id = (num - min_num) / gap;
            bucket[id].first = min(bucket[id].first, num);
            bucket[id].second = max(bucket[id].second, num);
        }
        int ans = 0;
        int prev_max = min_num;
        for(int i = 0; i < bucket.size(); i++){
            if(bucket[i].first == INT_MAX)
                continue;
            else{
                ans = max({ans, bucket[i].first - prev_max, bucket[i].second - bucket[i].first});
                prev_max = bucket[i].second;
            }
        }
        ans = max(ans, max_num - prev_max);
        return ans;
    }
};