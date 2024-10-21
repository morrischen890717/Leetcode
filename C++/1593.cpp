class Solution {
public:
    int solve(string& s, unordered_set<string>& us, int i){
        if(i >= s.length())
            return 0;
        int max_split = INT_MIN;
        string cur;
        for(int j = i; j < s.length(); j++){
            cur += s[j];
            if(us.count(cur) == 0){
                us.insert(cur);
                max_split = max(max_split, 1 + solve(s, us, j + 1));
                us.erase(cur);
            }
        }
        return max_split;
    }
    int maxUniqueSplit(string s) {
        unordered_set<string> us;
        return solve(s, us, 0);
    }
};