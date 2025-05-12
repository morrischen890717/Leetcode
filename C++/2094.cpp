class Solution {
public:
    void solve(vector<int>& cnt, int d, int num, vector<int>& ans){
        if(d == 3){
            if(num % 2 == 0)
                ans.push_back(num);
            return;
        }
        for(int i = 0; i < cnt.size(); i++){
            if((d == 0 && i == 0) || cnt[i] == 0)
                continue;
            cnt[i]--;
            solve(cnt, d + 1, num * 10 + i, ans);
            cnt[i]++;
        }
        return;
    }
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ans;
        vector<int> cnt(10, 0);
        int n = digits.size();
        for(int digit: digits){
            cnt[digit]++;
        }
        solve(cnt, 0, 0, ans);
        return ans;
    }
};