class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(int num: nums){
            int divisor = 0, bound = sqrt(num);
            for(int i = 2; i <= bound; i++){
                if(num % i == 0){
                    if(divisor == 0)
                        divisor = i;
                    else{
                        divisor = 0;
                        break;
                    }
                }
            }
            if(divisor != 0 && divisor != num / divisor)
                ans += (1 + num + divisor + num / divisor);
        }
        return ans;
    }
};