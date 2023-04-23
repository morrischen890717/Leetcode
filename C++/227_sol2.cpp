class Solution {
public:
    int cal(int op1, int op2, char oper){
        if(oper == '+')
            return op1 + op2;
        else if(oper == '-')
            return op1 - op2;
        else if(oper == '*')
            return op1 * op2;
        else if(oper == '/')
            return op1 / op2;
        return -1;
    }
    int calculate(string s) {  // using stack/deque
        int n = s.length();
        int op1, op2 = 0;
        char oper;
        deque<int> st;
        deque<char> operators;
        for(int i = 0; i < n; i++){
            if(s[i] == ' ')
                continue;
            else if(isdigit(s[i])){
                op2 = op2 * 10 + (s[i] - '0');
            }
            else{
                if(st.empty() || operators.back() == '+' || operators.back() == '-'){
                    st.push_back(op2);
                    operators.push_back(s[i]);
                }
                else{
                    op1 = st.back();
                    oper = operators.back();
                    st.pop_back();
                    operators.pop_back();
                    st.push_back(cal(op1, op2, oper));
                    operators.push_back(s[i]);
                }
                op2 = 0;
            }
        }
        if(!operators.empty() && (operators.back() == '*' || operators.back() == '/')){
            op1 = st.back();
            oper = operators.back();
            st.pop_back();
            operators.pop_back();
            op2 = cal(op1, op2, oper);
        }
        st.push_back(op2);
        op1 = st.front();
        st.pop_front();
        while(!st.empty() && !operators.empty()){
            op2 = st.front();
            oper = operators.front();
            st.pop_front();
            operators.pop_front();
            op1 = cal(op1, op2, oper);
        }
        return op1;
    }
};