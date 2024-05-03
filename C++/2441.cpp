class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans = -1;
        unordered_set<int> s;
        for(int num: nums){
            if(s.count(-num))
                ans = max(ans, abs(num));
            s.insert(num);
        }
        return ans;
    }
};