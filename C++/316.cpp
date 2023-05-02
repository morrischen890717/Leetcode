class Solution {
public:
    string removeDuplicateLetters(string s) {
        // reference: https://leetcode.com/problems/remove-duplicate-letters/solutions/1859410/java-c-detailed-visually-explained/
        vector<int> last(26, -1);   // the last index where each char appears in string s
        vector<bool> put(26, false);    // if the char exists in stack now
        stack<char> st;
        int len = s.length();
        for(int i = 0; i < len; i++){
            last[s[i] - 'a'] = i;
        }
        for(int i = 0; i < len; i++){
            if(put[s[i] - 'a']) // s[i] already in the stack
                continue;
            while(!st.empty() && s[i] < st.top() && last[st.top() - 'a'] > i){
                /*
                only if current char smaller than the char in the stack and 
                that char must appear again in the rest of the string can we pop that char from the stack
                */
                put[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(s[i]);
            put[s[i] - 'a'] = true;
        }
        string ans;
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};