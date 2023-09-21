class Solution {
public:
    string smallestSubsequence(string s) {
        // using monotonic stack
        // time complexity: O(N), space complexity: O(1), where st stores 26 values at most
        string ans;
        vector<int> cnt(26, 0);
        stack<char> st;
        vector<bool> exist(26, false); // check if the char is already in the stack or not
        for(char c: s){
            cnt[c - 'a']++;
        }
        for(char c: s){
            cnt[c - 'a']--;
            if(exist[c - 'a']) // if c is already in the stack, then we do not need to update the stack
                continue;
            while(!st.empty() && st.top() > c && cnt[st.top() - 'a'] > 0){ // cnt[st.top() - 'a] > 0 means that there is another st.top() after c (it is not the last one)
                exist[st.top() - 'a'] = false;
                st.pop();
            }
            exist[c - 'a'] = true;
            st.push(c);
        }
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};