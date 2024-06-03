class Solution {
public:
    int countTriplets(vector<int>& arr) {
        // using prefix sum
        // time complexity: O(N), space complexity: O(N)
        // reference: https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/solutions/623747/java-c-python-one-pass-o-n-4-to-o-n/?envType=daily-question&envId=2024-05-30
        int ans = 0;
        int n = arr.size();
        unordered_map<int, int> cnt, sum; // sum[i] stands for the sum of the ids which has arr number i
        cnt[0] = 1;
        sum[0] = -1;
        for(int i = 1; i < n; i++){
            arr[i] ^= arr[i - 1];
        }
        for(int i = 0; i < n; i++){
            ans += cnt[arr[i]] * (i - 1) - sum[arr[i]];
            cnt[arr[i]]++;
            sum[arr[i]] += i;
        }
        return ans;
    }
};