class Solution {
public:
    string removeDuplicates(string s, int k) {
        // using stack
        stack<pair<char, int>> st;
        for(char c: s){
            if(st.empty() || st.top().first != c){
                while(!st.empty() && st.top().second >= k){
                    st.top().second %= k;
                    if(st.top().second == 0)
                        st.pop();
                }
            }
            if(st.empty() || st.top().first != c)
                st.push({c, 1});
            else
                st.top().second++;
        }
        while(!st.empty() && st.top().second >= k){
            st.top().second %= k;
            if(st.top().second == 0)
                st.pop();
        }
        string ans = "";
        while(!st.empty()){
            string ss(st.top().second, st.top().first);
            ans = ss + ans;
            st.pop();
        }
        return ans;
    }
};