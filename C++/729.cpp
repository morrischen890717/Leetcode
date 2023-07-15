class MyCalendar {
public:
    set<pair<int, int>> s;
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        set<pair<int, int>>::iterator it = s.find({start, end});
        if(it != s.end()) // already exists in set
            return false;
        s.insert({start, end});
        it = s.find({start, end});
        int prevEnd, nextStart;
        if(it == s.begin())
            prevEnd = -1;
        else{
            it--;
            prevEnd = it->second;
            it++;
        }
        it++;
        if(it == s.end())
            nextStart = INT_MAX;
        else
            nextStart = it->first;
        it--;
        if(prevEnd <= start && end <= nextStart)
            return true;
        s.erase(it);
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */