class Solution {
public:
    int cnt1(string& s){
        int cnt = 0;
        for(char& c: s){
            if(c == '1')
                cnt++;
        }
        return cnt;
    }
    int numberOfBeams(vector<string>& bank) {
        int ans = 0;
        int m = bank.size(), n = bank[0].size();
        int prev = 0;
        for(string& s: bank){
            int cnt = cnt1(s);
            if(cnt > 0){
                ans += prev * cnt;
                prev = cnt;
            }
        }
        return ans;
    }
};