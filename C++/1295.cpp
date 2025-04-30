class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(int num: nums){
            int cnt = 0;
            while(num){
                cnt++;
                num /= 10;
            }
            if(cnt % 2 == 0)
                ans++;
        }
        return ans;
    }
};