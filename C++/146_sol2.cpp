class LRUCache {
public:
    int capacity;
    unordered_map<int, int> m;
    queue<int> q;
    unordered_map<int, int> queue_num;
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(m.count(key) > 0){
            q.push(key);
            queue_num[key]++;
            return m[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.count(key) > 0){
            m[key] = value;
            q.push(key);
            queue_num[key]++;
        }
        else if(m.size() < capacity){
            m[key] = value;
            q.push(key);
            queue_num[key] = 1;
        }
        else{
            int pop_key;
            do{
                pop_key = q.front();
                q.pop();
                queue_num[pop_key]--;
            } while(queue_num[pop_key] > 0);
            m.erase(pop_key);
            put(key, value);
        }
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */