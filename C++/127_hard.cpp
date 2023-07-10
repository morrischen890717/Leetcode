class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        /*
        using BFS + unordered_set
        reference: https://leetcode.com/problems/word-ladder/solutions/40707/c-bfs/
        */
        unordered_set<string> s(wordList.begin(), wordList.end());
        int step = 1;
        queue<string> q;
        q.push(beginWord);
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                string cur = q.front();
                q.pop();
                if(cur == endWord)
                    return step;
                for(int j = 0; j < cur.length(); j++){
                    char tmp = cur[j];
                    for(int k = 0; k < 26; k++){
                        if(k == tmp - 'a')
                            continue;
                        cur[j] = 'a' + k;
                        unordered_set<string>::iterator it = s.find(cur);
                        if(it != s.end()){
                            q.push(*it);
                            s.erase(*it); // improve execution time a lot
                        }
                    }
                    cur[j] = tmp;
                }
            }
            step++;
        }
        return 0;
    }
};