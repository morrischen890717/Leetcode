class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        // using BFS
        queue<int> q;
        vector<int> visited(jug1Capacity + jug2Capacity + 1, 0);
        vector<int> steps = {jug1Capacity, -jug1Capacity, jug2Capacity, -jug2Capacity};
        q.push(0);
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            if(visited[cur])
                continue;
            visited[cur] = 1;
            if(cur == targetCapacity)
                return true;
            for(auto& step: steps){
                if(cur + step >= 0 && cur + step <= jug1Capacity + jug2Capacity){
                    q.push(cur + step);
                }
            }
        }
        return false;
    }
};