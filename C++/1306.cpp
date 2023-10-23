class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        // using BFS
        // time complexity: O(N)
        int n = arr.size();
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                int id = q.front();
                q.pop();
                if(arr[id] == 0)
                    return true;
                if(id + arr[id] < n && !visited[id + arr[id]]){
                    visited[id + arr[id]] = true;
                    q.push(id + arr[id]);
                }
                if(id - arr[id] >= 0 && !visited[id - arr[id]]){
                    visited[id - arr[id]] = true;
                    q.push(id - arr[id]);
                }
            }
        }
        return false;
    }
};