class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // using BFS
        int step = 0;
        queue<int> q;
        vector<bool> visited(10000, false);
        for(string& deadend: deadends){
            visited[stoi(deadend)] = true;
        }
        q.push(stoi(target));
        visited[stoi(target)] = true;
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                int cur = q.front();
                q.pop();
                if(cur == 0)
                    return step;
                for(int j = 0; j < 4; j++){
                    int num = pow(10, j);
                    int increase = cur + num, decrease = cur - num;
                    if(increase / (num * 10) != cur / (num * 10))
                        increase -= num * 10;
                    if(decrease < 0 || decrease / (num * 10) != cur / (num * 10))
                        decrease += num * 10;
                    if(!visited[increase]){
                        visited[increase] = true;
                        q.push(increase);
                    }
                    if(!visited[decrease]){
                        visited[decrease] = true;
                        q.push(decrease);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};