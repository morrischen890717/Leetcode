class Node {
public:
    int val;
    Node *prev, *next;
    Node(int val){
        this->val = val;
        prev = next = NULL;
    }
};
class CustomStack {
public:
    int n, maxSize;
    Node *head, *tail;
    CustomStack(int maxSize) {
        n = 0;
        this->maxSize = maxSize;
        head = new Node(0);
        tail = new Node(0);
        head->next = tail;
        tail->prev = head;
    }
    
    void push(int x) {
        if(n >= maxSize)
            return;
        n++;
        Node *cur = new Node(x);
        head->next->prev = cur;
        cur->next = head->next;
        head->next = cur;
        cur->prev = head;
        return;
    }
    
    int pop() {
        if(n == 0)
            return -1;
        n--;
        int val = head->next->val;
        head->next = head->next->next;
        head->next->prev = head;
        return val;
    }
    
    void increment(int k, int val) {
        Node *cur = tail->prev;
        for(int i = 0; i < min(k, n); i++){
            cur->val += val;
            cur = cur->prev;
        }
        return;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */