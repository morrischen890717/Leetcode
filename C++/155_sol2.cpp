class MinStack {
public:
    stack<pair<int, int>> st;
    int min_num;
    MinStack() {
        min_num = INT_MAX;
    }
    
    void push(int val) {
        min_num = min(min_num, val);
        st.push({val, min_num});
        return;
    }
    
    void pop() {
        st.pop();
        min_num = st.empty() ? INT_MAX : st.top().second;
        return;
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */