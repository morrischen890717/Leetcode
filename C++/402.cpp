class Solution {
public:
    string removeKdigits(string num, int k) {
        /*
        using stack (monotonic stack), time complexity: O(N)
        reference: https://leetcode.com/problems/remove-k-digits/solutions/1779458/c-easy-to-understand-stack-short-simple/
        */
        int len = num.length();
        if(len <= k)
            return "0";
        string ans;
        stack<char> st;
        for(int i = 0; i < len; i++){
            while(k > 0 && !st.empty() && num[i] < st.top()){ // k > 0 represents we still need to remove some char
                st.pop();
                k--;
            }
            st.push(num[i]);
            if(st.size() == 1 && st.top() == '0') // remove leading zero
                st.pop();
        }
        while(k > 0 && !st.empty()){
            st.pop();
            k--;
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return (ans.length() == 0 ? "0" : ans);
    }
};