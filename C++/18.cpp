class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> combination;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int c, d;
        long long sum;
        int tmp1, tmp2;
        for(int a = 0; a < n - 3; a++){
            for(int b = a + 1; b < n - 2; b++){
                c = b + 1;
                d = n - 1;
                while(c < d){
                    sum = 0;
                    sum += nums[a];
                    sum += nums[b];
                    sum += nums[c];
                    sum += nums[d];
                    if(sum == target){
                        combination = {nums[a], nums[b], nums[c], nums[d]};
                        ans.push_back(combination);
                        tmp1 = nums[c];
                        tmp2 = nums[d];
                        while(c < n - 1 && nums[c] == tmp1)
                            c++;
                        while(d >= 4 && nums[d] == tmp2)
                            d--;
                    }
                    else if(sum < target)
                        c++;
                    else
                        d--;
                }
                tmp1 = nums[b];
                while(b < n - 2 && nums[b] == tmp1)
                    b++;
                b--;
            }
            tmp1 = nums[a];
            while(a < n - 3 && nums[a] == tmp1)
                a++;
            a--;
        }
        return ans;
    }
};