class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int push_id = 0;
        int pop_val;
        int top_val;
        for(int i = 0; i < popped.size(); i++){
            pop_val = popped[i];
            top_val = (st.empty() ? -1 : st.top());
            while(top_val != pop_val){
                if(push_id < pushed.size()){
                    st.push(pushed[push_id]);
                    top_val = pushed[push_id];
                    push_id++;
                }
                else
                    return false;
            }
            st.pop();
        }
        return true;
    }
};