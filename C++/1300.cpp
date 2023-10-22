class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        // using sort()
        // time complexity: O(NlogN)
        // reference: https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/solutions/463306/java-c-python-just-sort-o-nlogn/
        int ans = -1, min_diff = INT_MAX;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int i = 0, sum = 0;
        while(i < n && arr[i] * (n - i) < target){
            target -= arr[i];
            i++;
        }
        return i == n ? arr[n - 1] : round((target - 0.1) / (n - i));
    }
};