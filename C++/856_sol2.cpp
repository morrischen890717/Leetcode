class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int len = s.length();
        for(char c: s){
            if(c == '(')
                st.push(-1);
            else{
                int sum = 0;
                while(!st.empty() && st.top() != -1){
                    sum += st.top();
                    st.pop();
                }
                st.pop(); // pop '('
                sum = sum == 0 ? 1 : 2 * sum;
                st.push(sum);
            }
        }
        int ans = 0;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};