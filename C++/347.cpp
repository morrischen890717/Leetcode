class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // using bucket sort, time complexity: O(N)
        int n = nums.size();
        unordered_map<int, int> cnt;
        vector<vector<int>> bucket(n + 1); // bucket[i] stores all elements which appears i times
        vector<int> ans;
        for(int i = 0; i < n; i++){
            cnt[nums[i]]++;
        }
        for(auto it = cnt.begin(); it != cnt.end(); it++){
            bucket[it->second].push_back(it->first);
        }
        for(int i = n; i >= 1 && k > 0; i--){
            for(int j = 0; j < bucket[i].size() && k > 0; j++, k--){
                ans.push_back(bucket[i][j]);
            }
        }
        return ans;
    }
};