class Solution {
public:
    string reverseParentheses(string s) {
        // using stack
        string ans;
        int len = s.length();
        stack<char> st;
        for(int i = 0; i < len; i++){
            if(s[i] == ')'){
                string cur = "";
                while(st.top() != '('){
                    cur += st.top();
                    st.pop();
                }
                st.pop();
                for(char c: cur){
                    st.push(c);
                }
            }
            else
                st.push(s[i]);
        }
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};