class MyCircularQueue {
public:
    vector<int> q;
    int size, end, cnt;
    MyCircularQueue(int k) {
        q = vector<int> (k);
        size = k;
        end = cnt = 0;
    }
    
    bool enQueue(int value) {
        if(cnt >= size)
            return false;
        end = (end + 1) % size;
        q[end] = value;
        cnt++;
        return true;
    }
    
    bool deQueue() {
        if(cnt == 0)
            return false;
        cnt--;
        return true;
    }
    
    int Front() {
        return (cnt == 0 ? -1 : q[(end - cnt + 1 + size) % size]);
    }
    
    int Rear() {
        return (cnt == 0 ? -1 : q[end]);
    }
    
    bool isEmpty() {
        return cnt == 0;
    }
    
    bool isFull() {
        return cnt == size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */