class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        // time complexity: O(N + 101 * 101)
        // reference: https://leetcode.com/problems/3sum-with-multiplicity/solutions/181131/c-java-python-o-n-101-101/
        const int MOD = 1e9 + 7;
        long long ans = 0;
        int n = arr.size();
        vector<long long> cnt(101, 0);
        for(int i = 0; i < n; i++){
            cnt[arr[i]]++;
        }
        for(int i = 0; i < cnt.size(); i++){
            for(int j = 0; j < cnt.size(); j++){
                int k = target - i - j;
                if(k < 0 || k >= cnt.size())
                    continue;
                if(i == j && j == k)
                    ans += cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / 6;
                else if(i == j && j != k)
                    ans += cnt[i] * (cnt[i] - 1) / 2 * cnt[k];
                else if(i < j && j < k)
                    ans += cnt[i] * cnt[j] * cnt[k];
                ans %= MOD;
            }
        }
        return ans;
    }
};