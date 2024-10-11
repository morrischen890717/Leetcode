class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> occupied;
        priority_queue<int, vector<int>, greater<int>> available;
        int targetTime = times[targetFriend][0];
        sort(times.begin(), times.end());
        int cur = 0;
        for(vector<int>& time: times){
            int chair = -1;
            while(!occupied.empty() && occupied.top().first <= time[0]){
                available.push(occupied.top().second);
                occupied.pop();
            }
            if(!available.empty()){
                chair = available.top();
                available.pop();
            }
            else
                chair = cur++;
            if(time[0] == targetTime)
                return chair;
            occupied.push({time[1], chair});
        }
        return -1;
    }
};