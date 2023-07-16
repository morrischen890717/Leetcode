class MyCalendarTwo {
public:
    map<int, int> m;
    MyCalendarTwo() {
    }
    
    bool book(int start, int end) {
        /*
        reference: https://leetcode.com/problems/my-calendar-ii/solutions/323479/simple-c-solution-using-built-in-map-same-as-253-meeting-rooms-ii/
        if there is no clash, a 'start' is always be followed by its corresponding end, so 'booked' will never be more than 1. 
        If two time periods are clashing, you will see two consecutive starts. 
        So, if there is only a double clash 'booked' can grow to 2. Similarly, if there is a triple clash then 'booked' can go to 3.
        */
        m[start]++;
        m[end]--;
        int booked = 0;
        for(map<int, int>::iterator it = m.begin(); it != m.end(); it++){
            booked += it->second;
            if(booked >= 3){
                m[start]--;
                m[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */