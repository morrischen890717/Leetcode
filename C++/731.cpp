class MyCalendarTwo {
public:
    vector<pair<int, int>> bookings, overlap;
    MyCalendarTwo() {

    }

    bool isOverlap(pair<int, int>& e, int start, int end){
        return max(e.first, start) < min(e.second, end);
    }
    
    bool book(int start, int end) {
        // reference: https://leetcode.com/problems/my-calendar-ii/solutions/5838400/understand-once-you-will-solve-on-your-own-no-array-used-less-code-with-added-video/?envType=daily-question&envId=2024-09-27
        for(pair<int, int>& e: overlap){
            if(isOverlap(e, start, end))
                return false;
        }
        for(pair<int, int>& e: bookings){
            if(isOverlap(e, start, end))
                overlap.push_back({max(e.first, start), min(e.second, end)});
        }
        bookings.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */