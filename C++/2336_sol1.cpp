class SmallestInfiniteSet {
public:
    int cur;
    set<int> s;
    SmallestInfiniteSet() {
        cur = 0;
    }
    
    int popSmallest() {
        if(!s.empty()){
            int e = *s.begin();
            s.erase(s.begin());
            return e;
        }
        else{
            cur++;
            return cur;
        }
    }
    
    void addBack(int num) {
        if(num <= cur)
            s.insert(num);
        return;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */