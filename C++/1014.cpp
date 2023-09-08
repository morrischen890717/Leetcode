class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        // time complexity: O(N), space complexity: O(1)
        // main idea: turn values[i] + values[j] + i - j into (values[i] + i) + (values[j] - j), maxNum stores the maximum number of (values[i] + i)
        int ans = 0;
        int n = values.size();
        int maxNum = values[0] - 0;
        for(int j = 1; j < n; j++){
            ans = max(ans, maxNum + values[j] - j);
            maxNum = max(maxNum, values[j] + j);
        }
        return ans;
    }
};