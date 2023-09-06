class Solution {
public:
    bool isValid(string s) {
        // using stack
        // time complexity: O(N), space complexity: O(N)
        stack<char> st;
        for(char c: s){
            if(c == 'c'){
                if(st.size() < 2 || st.top() != 'b')
                    return false;
                st.pop();
                if(st.size() < 1 || st.top() != 'a')
                    return false;
                st.pop();
            }
            else
                st.push(c);
        }
        return st.empty() ? true : false;
    }
};