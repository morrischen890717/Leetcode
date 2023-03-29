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
        if(this->m.count(key) > 0){
            this->q.push(key);
            this->queue_num[key]++;
            return this->m[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(this->m.count(key) > 0){
            this->m[key] = value;
            this->q.push(key);
            this->queue_num[key]++;
        }
        else if(this->m.size() < this->capacity){
            this->m[key] = value;
            this->q.push(key);
            this->queue_num[key] = 1;
        }
        else{
            int pop_key;
            do{
                pop_key = this->q.front();
                this->q.pop();
                this->queue_num[pop_key]--;
            } while(this->queue_num[pop_key] > 0);
            this->m.erase(pop_key);
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