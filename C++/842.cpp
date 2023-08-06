class Solution {
public:
    bool solve(string& num, int id, int prev1, int prev2, int cnt, vector<int>& ans){
        if(id == num.length())
            return cnt >= 3;
        if(num[id] == '0'){
            if(prev1 < 0 || prev1 + prev2 == 0){
                if(solve(num, id + 1, prev2, 0, cnt + 1, ans)){
                    ans.push_back(0);
                    return true;
                }
            }
            return false;
        }
        long long cur = 0;
        for(int i = id; i < num.length() && (prev1 < 0 || cur <= (long long)prev1 + prev2); i++){
            cur *= 10;
            cur += (num[i] - '0');
            if(cur > INT_MAX)
                break;
            if(prev1 < 0 || cur == (long long)prev1 + prev2){
                if(solve(num, i + 1, prev2, cur, cnt + 1, ans)){
                    ans.push_back(cur);
                    return true;
                }
            }
        }
        return false;
    }
    vector<int> splitIntoFibonacci(string num) {
        // using backtrack
        vector<int> ans;
        solve(num, 0, -1, -1, 0, ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};