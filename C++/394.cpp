class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        int len = s.length();
        int num = 0;
        for(int i = 0; i < len; i++){
            if(s[i] == ']'){
                string tmp;
                while(st.top() != "["){
                    tmp = st.top() + tmp;
                    st.pop();
                }
                st.pop(); // pop "["
                int times = stoi(st.top());
                st.pop();
                string new_tmp;
                for(int j = 0; j < times; j++){
                    new_tmp += tmp;
                }
                st.push(new_tmp);
            }
            else if(s[i] - '0' >= 0 && s[i] - '0' <= 9){
                num *= 10;
                num += (s[i] - '0');
            }
            else if(s[i] == '['){
                string num_s = to_string(num);
                st.push(num_s);
                string tmp;
                tmp += s[i];
                st.push(tmp);
                num = 0;
            }
            else{
                string tmp;
                tmp += s[i];
                st.push(tmp);
            }
        }
        string ans;
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};