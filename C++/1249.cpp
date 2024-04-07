class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int len = s.length();
        stack<pair<char, int>> st;
        for(int i = 0; i < len; i++){
            if(s[i] == '(')
                st.push({s[i], i});
            else if(s[i] == ')'){
                if(!st.empty() && st.top().first == '(')
                    st.pop();
                else
                    st.push({s[i], i});
            }
        }
        while(!st.empty()){
            s[st.top().second] = '.';
            st.pop();
        }
        s.erase(remove(s.begin(), s.end(), '.'), s.end());
        return s;
    }
};