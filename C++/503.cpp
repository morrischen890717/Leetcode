class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<pair<int, int>> st;
        for(int j = 0; j < 2; j++){ // we do 2 loop because the array is circular
            for(int i = 0; i < n; i++){
                while(!st.empty() && st.top().first < nums[i]){
                    ans[st.top().second] = nums[i];
                    st.pop();
                }
                st.push({nums[i], i});
            }
        }
        return ans;
    }
};