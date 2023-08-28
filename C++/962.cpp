class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        // using monotonic stack
        // time complexity: O(N), space complexity: O(N)
        // reference: https://leetcode.com/problems/maximum-width-ramp/solutions/208348/java-c-python-o-n-using-stack/
        int ans = 0;
        int n = nums.size();
        stack<int> st; // monotonic decreasing by the value in nums. st will just store its id but not its value
        st.push(0);
        for(int i = 1; i < n; i++){
            if(nums[i] < nums[st.top()])
                st.push(i);
        }
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && nums[i] >= nums[st.top()]){
                ans = max(ans, i - st.top());
                st.pop();
            }
        }
        return ans;
    }
};