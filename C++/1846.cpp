class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        // using sort and Greedy
        // time complexity: O(NlogN), space complexity: O(1)
        int n = arr.size();
        int max_val = INT_MIN;
        sort(arr.begin(), arr.end());
        for(int i = 0; i < n; i++){
            max_val = max(max_val, arr[i]);
            if(max_val < i + 1)
                return arr.back() > max_val ? i + 1 : i;
        }
        return n;
    }
};