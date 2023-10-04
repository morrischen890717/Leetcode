class MyHashMap {
private:
    vector<int> map;
public:
    MyHashMap() {
        map = vector<int> (1e6 + 1, -1);
    }
    
    void put(int key, int value) {
        map[key] = value;
        return;
    }
    
    int get(int key) {
        return map[key];
    }
    
    void remove(int key) {
        map[key] = -1;
        return;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */