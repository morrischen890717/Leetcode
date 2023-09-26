class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        // using monotonic stack
        // time complexity: O(N), space complexity: O(N)
        // reference: https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/solutions/339959/one-pass-o-n-time-and-space/
        int ans = 0;
        stack<int> st;
        st.push(INT_MAX);
        for(int num: arr){
            while(st.top() <= num){
                int mid = st.top();
                st.pop();
                ans += mid * min(st.top(), num); // choose one of them to combine
            }
            st.push(num);
        }
        while(st.size() > 2){
            int right = st.top();
            st.pop();
            ans += right * st.top();
        }
        return ans;
    }
};