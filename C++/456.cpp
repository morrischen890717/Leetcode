class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        // reference: https://leetcode.com/problems/132-pattern/solutions/94071/single-pass-c-o-n-space-and-time-solution-8-lines-with-detailed-explanation/
        int n = nums.size();
        stack<int> st;
        int num_j = INT_MIN;
        for(int i = n - 1; i >= 0; i--){
            if(nums[i] < num_j)
                return true;
            while(!st.empty() && nums[i] > st.top()){
                num_j = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};