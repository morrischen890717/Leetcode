class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        // using BFS, unordered_map, and sort()
        int n = watchedVideos.size();
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(id);
        visited[id] = true;
        while(!q.empty() && level > 0){
            int size = q.size();
            for(int i = 0; i < size; i++){
                int cur_id = q.front();
                q.pop();
                for(int neighbor: friends[cur_id]){
                    if(!visited[neighbor]){
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
            level--;
        }
        unordered_map<string, int> cnt;
        while(!q.empty()){
            int cur_id = q.front();
            q.pop();
            for(string& video: watchedVideos[cur_id]){
                cnt[video]++;
            }
        }
        vector<pair<int, string>> v;
        for(unordered_map<string, int>::iterator it = cnt.begin(); it != cnt.end(); it++){
            v.push_back({it->second, it->first});
        }
        sort(v.begin(), v.end());
        vector<string> ans;
        for(pair<int, string>& p: v){
            ans.push_back(p.second);
        }
        return ans;
    }
};