class Solution {
public:
    int getChange(vector<int>& arr1, vector<int>& arr2, int l, int r){
        if(l + 1 == r)
            return 0;
        int min = arr1[l], max = arr1[r];
        vector<int>::iterator it = upper_bound(arr2.begin(), arr2.end(), min);
        int pos = it - arr2.begin(); // start position in newArr2
        int end = pos + (r - l - 2); // end position in newArr2
        if(end >= arr2.size() || arr2[end] >= max)
            return -1;
        return r - l - 1;
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        /*
        using DP
        reference: https://leetcode.com/problems/make-array-strictly-increasing/solutions/377495/java-dp-solution-a-simple-change-from-longest-increasing-subsequence/
        */
        sort(arr2.begin(), arr2.end());
        vector<int> dp(arr1.size() + 2, INT_MAX);
        vector<int> newArr1(arr1.size() + 2);
        vector<int> newArr2;
        newArr1[0] = INT_MIN;
        newArr1.back() = INT_MAX;
        for(int i = 0; i < arr1.size(); i++){
            newArr1[i + 1] = arr1[i];
        }
        newArr2.push_back(arr2[0]);
        for(int i = 1; i < arr2.size(); i++){
            if(arr2[i] != arr2[i - 1])
                newArr2.push_back(arr2[i]);
        }

        int len1 = newArr1.size();
        dp[0] = 0;
        for(int j = 0; j < len1; j++){
            for(int i = 0; i < j; i++){
                // dp[i] == INT_MAX means that there is no way to make newArr1[0] ~ newArr1[i] strictly increasing
                if(newArr1[j] <= newArr1[i] || dp[i] == INT_MAX)
                    continue;
                int change = getChange(newArr1, newArr2, i, j);
                if(change != -1)
                    dp[j] = min(dp[j], dp[i] + change);
            }
        }
        return (dp[len1 - 1] == INT_MAX ? -1 : dp[len1 - 1]);
    }
};