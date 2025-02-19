class Solution {
public:
    string solve(int n, vector<char>& letters, string& cur, int& k){
        if(cur.length() == n){
            k--;
            return k == 0 ? cur : "";
        }
        for(char c: letters){
            if(!cur.empty() && c == cur.back())
                continue;
            cur += c;
            string res = solve(n, letters, cur, k);
            if(!res.empty())
                return res;
            cur.pop_back();
        }
        return "";
    }
    string getHappyString(int n, int k) {
        vector<char> letters = {'a', 'b', 'c'};
        string cur;
        return solve(n, letters, cur, k);
    }
};