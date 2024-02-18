class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        // using sort and priority_queue
        int size = meetings.size();
        sort(meetings.begin(), meetings.end());
        priority_queue<int, vector<int>, greater<int>> unused; // room id
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> used; // {end time, room id}
        vector<int> cnt(n, 0);
        for(int i = 0; i < n; i++){
            unused.push(i);
        }
        for(int i = 0; i < size; i++){
            while(!used.empty() && used.top().first <= meetings[i][0]){ // check if there is any used room which is going to be available
                unused.push(used.top().second);
                used.pop();
            }
            if(!unused.empty()){ // if there is an available room now
                cnt[unused.top()]++;
                used.push({meetings[i][1], unused.top()});
                unused.pop();
            }
            else{ // all rooms are used now
                cnt[used.top().second]++;
                used.push({used.top().first + (meetings[i][1] - meetings[i][0]), used.top().second});
                used.pop();
            }
        }
        int max_cnt = -1, room;
        for(int i = 0; i < n; i++){
            if(cnt[i] > max_cnt){
                max_cnt = cnt[i];
                room = i;
            }
        }
        return room;
    }
};