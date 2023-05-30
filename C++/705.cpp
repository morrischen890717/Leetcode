class MyHashSet {
public:
    unordered_map<int, bool> exist;
    MyHashSet() {
        
    }
    
    void add(int key) {
        exist[key] = true;
        return;
    }
    
    void remove(int key) {
        exist[key] = false;
        return;
    }
    
    bool contains(int key) {
        return exist[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */