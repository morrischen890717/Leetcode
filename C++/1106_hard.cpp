class Solution {
public:
    bool parseBoolExpr(string expression) {
        // using stack
        // time complexity: O(N), space complexity: O(N)
        // reference: https://leetcode.com/problems/parsing-a-boolean-expression/solutions/5939345/beats-100-optimized-solution-python-java-c-o-n-o-n/?envType=daily-question&envId=2024-10-20
        stack<char> st;
        for(char c: expression){
            if(c == 't' || c == 'f' || c == '!' || c == '&' || c == '|')
                st.push(c);
            else if(c == ')'){
                bool hasTrue = false, hasFalse = false;
                while(st.top() == 't' || st.top() == 'f'){
                    hasTrue = st.top() == 't' ? true : hasTrue;
                    hasFalse = st.top() == 'f' ? true : hasFalse;
                    st.pop();
                }
                char op = st.top();
                st.pop();
                if(op == '!')
                    st.push(hasTrue ? 'f' : 't');
                else if(op == '&')
                    st.push(hasFalse ? 'f' : 't');
                else if(op == '|')
                    st.push(hasTrue ? 't' : 'f');
            }
        }
        return st.top() == 't';
    }
};