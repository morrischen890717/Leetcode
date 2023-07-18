class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<string> q;
        vector<bool> visited(10000, false);
        int turns = 0;
        for(string& deadend: deadends){
            visited[stoi(deadend)] = true;
        }
        q.push("0000");
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                string cur = q.front();
                q.pop();
                if(cur == target)
                    return turns;
                if(visited[stoi(cur)])
                    continue;
                visited[stoi(cur)] = true;
                for(int j = 0; j < 4; j++){
                    string next = cur;
                    next[j] = next[j] == '9' ? '0' : next[j] + 1;
                    q.push(next);
                    next = cur;
                    next[j] = next[j] == '0' ? '9' : next[j] - 1;
                    q.push(next);
                }
            }
            turns++;
        }
        return -1;
    }
};