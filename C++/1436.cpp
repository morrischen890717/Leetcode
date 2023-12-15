class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> ans;
        unordered_set<string> not_ans;
        for(vector<string>& path: paths){
            string start = path[0], end = path[1];
            if(ans.count(start))
                ans.erase(start);
            not_ans.insert(start);
            if(!not_ans.count(end))
                ans.insert(end);
        }
        return *ans.begin();
    }
};