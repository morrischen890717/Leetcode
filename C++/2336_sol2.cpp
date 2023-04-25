class SmallestInfiniteSet {
public:
    vector<int> v;
    SmallestInfiniteSet() {
        vector<int> temp(1000,1);
        v = temp;
    }
    
    int popSmallest() {
        int e;
        for(int i = 0; i < 1000; i++){
            if(v[i]){
                v[i] = 0;
                e = i + 1;
                break;
            }
        }
        return e;
    }
    
    void addBack(int num) {
        v[num - 1] = 1;
        return;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */