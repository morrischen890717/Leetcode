class Solution {
public:
    string simplifyPath(string path) {
        deque<string> st;  // deque is a double-ended queue
        string s = "";
        string result = "";
        path += "/";
        int len = path.length();
        for(int i = 0; i < len; i++){
            if(path[i] == '/'){
                if(s == "")
                    continue;
                else if(s == ".")
                    s = "";
                else if(s == ".."){
                    s = "";
                    if(!st.empty())
                        st.pop_back();
                }
                else{
                    st.push_back(s);
                    s = "";
                }
            }
            else{
                s += path[i];
            }
        }
        while(!st.empty()){
            result += "/";
            result += st.front();
            st.pop_front();
        }
        return result == "" ? "/" : result;
    }
};