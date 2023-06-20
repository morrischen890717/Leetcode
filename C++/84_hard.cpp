class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        /*
        time complexity: O(N)
        reference: https://leetcode.com/problems/largest-rectangle-in-histogram/solutions/28902/5ms-o-n-java-solution-explained-beats-96/?envType=featured-list&envId=top-interview-questions
        */
        int n = heights.size();
        int ans = 0;
        // lessLeft[i] stands for the first id of the element which is on heights[i] left side and its height is less than heights[i], lessRight is same as lessLeft but for right direction
        vector<int> lessLeft(n), lessRight(n);
        for(int i = 0; i < n; i++){
            int id = i - 1;
            while(id >= 0 && heights[id] >= heights[i]){
                id = lessLeft[id];
            }
            lessLeft[i] = id;
        }
        for(int i = n - 1; i >= 0; i--){
            int id = i + 1;
            while(id < n && heights[id] >= heights[i]){
                id = lessRight[id];
            }
            lessRight[i] = id;
        }
        for(int i = 0; i < n; i++){
            // rectangle: l = lessLeft[i] + 1, r = lessRight[i] - 1. heights[j] >= heights[i], for heights[j] where l <= j <= r
            ans = max(ans, heights[i] * (lessRight[i] - lessLeft[i] - 1));
        }
        return ans;
    }
};