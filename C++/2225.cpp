class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2);
        map<int, int> lose;
        for(vector<int>& match: matches){
            if(lose.count(match[0]) == 0)
                lose[match[0]] = 0;
            lose[match[1]]++;
        }
        for(map<int, int>::iterator it = lose.begin(); it != lose.end(); it++){
            if(it->second == 0)
                ans[0].push_back(it->first);
            else if(it->second == 1)
                ans[1].push_back(it->first);
        }
        return ans;
    }
};