class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int minNum = INT_MAX, maxNum = INT_MIN;
        for(int num: nums){
            minNum = min(minNum, num);
            maxNum = max(maxNum, num);
        }
        return max(0, maxNum - minNum - 2 * k);
    }
};