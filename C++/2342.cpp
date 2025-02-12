class Solution {
public:
    int sumOfDigits(int num){
        int sum = 0;
        while(num){
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        int ans = -1;
        int n = nums.size();
        unordered_map<int, int> m;
        for(int num: nums){
            int sum = sumOfDigits(num);
            if(m.count(sum)){
                ans = max(ans, m[sum] + num);
                m[sum] = max(m[sum], num);
            }
            else
                m[sum] = num;
        }
        return ans;
    }
};