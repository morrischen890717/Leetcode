class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ans;
        int len1 = s.length(), len2 = part.length();
        stack<char> st;
        for(char c: s){
            st.push(c);
            int id = len2 - 1;
            stack<char> tmp;
            while(id >= 0 && !st.empty() && st.top() == part[id]){
                id--;
                tmp.push(st.top());
                st.pop();
            }
            if(id < 0)
                id == len2 - 1;
            else{
                while(!tmp.empty()){
                    st.push(tmp.top());
                    tmp.pop();
                }
            }
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};