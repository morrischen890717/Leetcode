class CustomStack {
public:
    vector<int> st;
    int i, size, maxSize;
    CustomStack(int maxSize) {
        st = vector<int> (maxSize, 0);
        i = size = 0;
        this->maxSize = maxSize;
    }
    
    void push(int x) {
        if(size < maxSize){
            size++;
            st[i % maxSize] = x;
            i++;
        }
        return;
    }
    
    int pop() {
        if(size == 0)
            return -1;
        size--;
        i--;
        return st[i % maxSize];
    }
    
    void increment(int k, int val) {
        for(int j = i - size; j < min(i - size + k, i); j++){
            st[j % maxSize] += val;
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