class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> pos(26);
        for(int i = 0; i < order.length(); i++){
            pos[order[i] - 'a'] = i;
        }
        // self-defined inline compare function ([&] means that you capture the automatic variables by reference)
        sort(s.begin(), s.end(), [&](char a, char b){
            return pos[a - 'a'] < pos[b - 'a'];
        });
        return s;
    }
};