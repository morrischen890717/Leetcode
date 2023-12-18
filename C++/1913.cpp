class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int max1 = INT_MIN, max2 = INT_MIN, min1 = INT_MAX, min2 = INT_MAX;
        for(int num: nums){
            if(num >= max1){
                max2 = max1;
                max1 = num;
            }
            else if(num >= max2)
                max2 = num;
            if(num <= min1){
                min2 = min1;
                min1 = num;
            }
            else if(num <= min2)
                min2 = num;
        }
        return (max1 * max2) - (min1 * min2);
    }
};