class MyCircularDeque {
public:
    vector<int> q;
    int n, cnt, head, end;
    MyCircularDeque(int k) {
        q = vector<int> (k, -1);
        n = k;
        cnt = end = 0;
        head = 1;
    }
    
    bool insertFront(int value) {
        if(cnt == n)
            return false;
        head = (head - 1 + n) % n;
        q[head] = value;
        cnt++;
        return true;
    }
    
    bool insertLast(int value) {
        if(cnt == n)
            return false;
        end = (end + 1) % n;
        q[end] = value;
        cnt++;
        return true;
    }
    
    bool deleteFront() {
        if(cnt == 0)
            return false;
        head = (head + 1) % n;
        cnt--;
        return true;
    }
    
    bool deleteLast() {
        if(cnt == 0)
            return false;
        end = (end - 1 + n) % n;
        cnt--;
        return true;
    }
    
    int getFront() {
        return cnt == 0 ? -1 : q[head];
    }
    
    int getRear() {
        return cnt == 0 ? -1 : q[end];
    }
    
    bool isEmpty() {
        return cnt == 0;
    }
    
    bool isFull() {
        return cnt == n;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */