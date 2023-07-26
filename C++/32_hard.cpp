class Solution {
public:
    int longestValidParentheses(string s) {
        // using stack
        // time complexity: O(N)
        // reference: https://leetcode.com/problems/longest-valid-parentheses/solutions/14126/my-o-n-solution-using-a-stack/
        int len = s.length();
        stack<int> st;
        for(int i = 0; i < len; i++){
            if(s[i] == ')' && (!st.empty() && s[st.top()] == '('))
                st.pop();
            else
                st.push(i);
        }
        int ans = 0, r = len;
        while(!st.empty()){
            ans = max(ans, r - st.top() - 1); // not counting head(st.top()) and end(r)
            r = st.top();
            st.pop();
        }
        ans = max(ans, r);
        return ans;
    }
};