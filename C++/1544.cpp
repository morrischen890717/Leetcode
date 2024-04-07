class Solution {
public:
    string makeGood(string s) {
        int len = s.length();
        int d = abs('A' - 'a');
        stack<char> st;
        for(char c: s){
            if(!st.empty() && abs(c - st.top()) == d)
                st.pop();
            else
                st.push(c);
        }
        string ans = "";
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};