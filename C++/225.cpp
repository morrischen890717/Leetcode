class MyStack {
private:
    queue<int> q;
public:
    MyStack() {
        
    }
    
    void push(int x) { // O(N) time
        int n = q.size();
        q.push(x);
        for(int i = 0; i < n; i++){
            q.push(q.front());
            q.pop();
        }
        return;
    }
    
    int pop() { // O(1) time
        int res = q.front();
        q.pop();
        return res;
    }
    
    int top() { // O(1) time
        return q.front();
    }
    
    bool empty() { // O(1) time
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */