class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        // using sort and priority_queue
        // time complexity: O(NlogN)
        // reference: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/solutions/510263/java-c-python-priority-queue/
        priority_queue<int, vector<int>, greater<int>> pq;
        sort(events.begin(), events.end()); // time complexity: O(NlogN)
        int n = events.size();
        int day = 0, i = 0, ans = 0;
        while(!pq.empty() || i < n){ // time complexity: O(N)
            if(pq.empty())
                day = events[i][0];
            while(i < n && events[i][0] <= day){
                pq.push(events[i][1]);
                i++;
            }
            day++;
            ans++;
            pq.pop();
            while(!pq.empty() && pq.top() < day){
                pq.pop();
            }
        }
        return ans;
    }
};