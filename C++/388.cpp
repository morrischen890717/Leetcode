class Solution {
public:
    int lengthLongestPath(string input) {
        input += '\n';
        int n = input.length();
        stack<int> st;
        string cur;
        int len = 0;
        int ans = 0;
        int slash_cnt = 100;
        for(int i = 0; i < n; i++){
            if(input[i] == '\n'){
                slash_cnt = 0;
                len += cur.length();
                if(cur.find('.') != std::string::npos){
                    ans = max(ans, len);
                    st.push(cur.length());
                }
                else{ // it is directory
                    len += 1; // += 1 because of '/' for directory
                    st.push(cur.length() + 1); // + 1 because of '/' for directory
                }
                cur = "";
            }
            else if(input[i] == '\t'){
                slash_cnt++;
            }
            else{
                while(slash_cnt < st.size()){
                    len -= st.top();
                    st.pop();
                }
                cur += input[i];
            }
        }
        return ans;
    }
};