class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> ans;
        unordered_map<int, int> color, used;
        int cnt = 0;
        for(vector<int>& q: queries){
            if(color.count(q[0]) && used.count(color[q[0]])){
                used[color[q[0]]]--;
                if(used[color[q[0]]] == 0)
                    cnt--;
            }
            color[q[0]] = q[1];
            used[q[1]]++;
            if(used[q[1]] == 1)
                cnt++;
            ans.push_back(cnt);
        }
        return ans;
    }
};