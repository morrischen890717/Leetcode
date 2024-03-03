class Solution {
public:
    int find(vector<int>& parent, int i){
        return parent[i] == i ? i : find(parent, parent[i]);
    }
    void uni(vector<int>& parent, int i, int j){
        int parent_i = find(parent, i), parent_j = find(parent, j);
        if(parent_i == parent_j)
            return;
        if(parent_i < parent_j)
            parent[parent_j] = parent_i;
        else
            parent[parent_i] = parent_j;
        return;
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        // using sort and Union-Find
        // reference: https://leetcode.com/problems/find-all-people-with-secret/solutions/1599815/c-union-find/?envType=daily-question&envId=2024-02-24
        vector<int> ans;
        vector<int> parent(n);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
        sort(meetings.begin(), meetings.end(), [](vector<int>& a, vector<int>& b){
            return a[2] < b[2];
        });
        uni(parent, 0, firstPerson);
        for(int i = 0; i < meetings.size(); ){
            int time = meetings[i][2];
            vector<int> now_meeting;
            while(i < meetings.size() && meetings[i][2] == time){
                uni(parent, meetings[i][0], meetings[i][1]);
                now_meeting.push_back(meetings[i][0]);
                now_meeting.push_back(meetings[i][1]);
                i++;
            }
            for(int id: now_meeting){
                if(find(parent, id) != find(parent, 0))
                    parent[id] = id; // reset
            }
        }
        int root = find(parent, 0);
        for(int i = 0; i < n; i++){
            if(find(parent, i) == root)
                ans.push_back(i);
        }
        return ans;
    }
};