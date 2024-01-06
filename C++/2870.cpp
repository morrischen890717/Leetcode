class Solution {
public:
    int minOperations(vector<int>& nums) {
        // using unordered_map and Greedy
        int ans = 0;
        unordered_map<int, int> cnt;
        for(int num: nums){
            cnt[num]++;
        }
        for(unordered_map<int, int>::iterator it = cnt.begin(); it != cnt.end(); it++){
            if(it->second == 1)
                return -1;
            ans += it->second % 3 ? it->second / 3 + 1 : it->second / 3; // let the number of delete_3 to be maximum
        }
        return ans;
    }
};