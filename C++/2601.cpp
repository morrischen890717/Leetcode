class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        vector<bool> isPrime(1001, true);
        isPrime[0] = isPrime[1] = false;
        for(int i = 2; i * i <= 1000; i++){
            for(int j = 2 * i; j <= 1000; j += i){
                isPrime[j] = false;
            }
        }
        vector<int> prime;
        for(int i = 0; i < 1001; i++){
            if(isPrime[i])
                prime.push_back(i);
        }
        int prev = nums.back();
        for(int i = n - 2; i >= 0; i--){
            if(nums[i] < prev)
                prev = nums[i];
            else{
                bool valid = false;
                for(int p: prime){
                    if(p >= nums[i])
                        break;
                    else if(nums[i] - p < prev){
                        prev = nums[i] - p;
                        valid = true;
                        break;
                    }
                }
                if(!valid)
                    return false;
            }
        }
        return true;
    }
};