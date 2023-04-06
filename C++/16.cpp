class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
       int n = nums.size();
       sort(nums.begin(), nums.end());
       int l, r;
       int ans = 10000000;
       int sum;
       for(int i = 0; i < n; i++){
           l = i + 1;
           r = n - 1;
           while(l < r){
                sum = nums[i] + nums[l] + nums[r];
                if(abs(sum - target) < abs(ans - target))
                    ans = sum;
                if(sum == target)
                    return target;
                else if (sum < target)
                    l++;
                else
                    r--;
           }
       }
       return ans; 
    }
};