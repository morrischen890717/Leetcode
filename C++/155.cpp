class Node {
public:
    int val;
    int min;
    Node *prev;
    Node(int val, int min, Node* prev){
        this->val = val;
        this->min = min;
        this->prev = prev;
    }
};

class MinStack {
public:
    Node *end;
    MinStack() {
        end = NULL;
    }
    
    void push(int val) {
        if(!end)
            end = new Node(val, val, NULL);
        else{
            Node *next = new Node(val, min(val, end->min), end);
            end = next;
        }
        return;
    }
    
    void pop() {
        end = end->prev;
        return;
    }
    
    int top() {
        return end->val;
    }
    
    int getMin() {
        return end->min;
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