class Solution {
public:
    string minRemoveToMakeValid(string s) {
        // using stack
        int len = s.length();
        stack<pair<char, int>> st;
        for(int i = 0; i < len; i++){
            if(s[i] == '(')
                st.push({'(', i});
            else if(s[i] == ')'){
                if(!st.empty() && st.top().first == '(')
                    st.pop();
                else
                    st.push({')', i});
            }
        }
        while(!st.empty()){
            s = s.substr(0, st.top().second) + s.substr(st.top().second + 1);
            st.pop();
        }
        return s;
    }
};