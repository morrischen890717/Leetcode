class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int ans = 0;
        int n = dominoes.size();
        unordered_map<string, int> cnt;
        for(vector<int>& domino: dominoes){
            if(domino[0] > domino[1])
                swap(domino[0], domino[1]);
            cnt[to_string(domino[0]) + "," + to_string(domino[1])]++;
        }
        for(unordered_map<string, int>::iterator it = cnt.begin(); it != cnt.end(); it++){
            ans += it->second * (it->second - 1) / 2;
        }
        return ans;
    }
};