class ExamRoom {
public:
    set<int> s;
    int size;
    ExamRoom(int n) {
        size = n;
    }
    
    int seat() {
        if(s.empty()){
            s.insert(0);
            return 0;
        }
        int prev = -1;
        int seat = -1, maxDist = 0;
        int d;
        for(set<int>::iterator it = s.begin(); it != s.end(); it++){
            d = *it - prev;
            if(d / 2 > maxDist){
                maxDist = prev == -1 ? d - 1 : d / 2;
                seat = prev == -1 ? prev + 1 : (*it + prev) / 2;
            }
            prev = *it;
        }
        if(size - prev - 1 > maxDist)
            seat = size - 1;
        s.insert(seat);
        return seat;
    }
    
    void leave(int p) {
        s.erase(p);
        return;
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */