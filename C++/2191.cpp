class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> m;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                m[nums[i]] = mapping[0];
                continue;
            }
            m[nums[i]] = 0;
            int tmp = nums[i];
            int j = 1;
            while(tmp){
                m[nums[i]] += j * mapping[tmp % 10];
                tmp /= 10;
                j *= 10;
            }
        }
        sort(nums.begin(), nums.end(), [&](int a, int b){
            return m[a] < m[b];
        });
        return nums;
    }
};