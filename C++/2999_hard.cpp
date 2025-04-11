class Solution {
public:
    long long dfs(vector<long long>& cnt, int i, int limit, string& boundary, const string& s){
        if(boundary.length() < s.length())
            return 0;
        if(i == boundary.length() - s.length())
            return boundary.substr(i) >= s;
        int digits = min(limit + 1, boundary[i] - '0') - 1 + (i > 0);
        return cnt[boundary.length() - 1 - i] * digits + (boundary[i] - '0' <= limit ? dfs(cnt, i + 1, limit, boundary, s) : 0);
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, const string &s) {
        // reference: https://leetcode.com/problems/count-the-number-of-powerful-integers/solutions/4518902/count-dfs/?envType=daily-question&envId=2025-04-10
        vector<long long> cnt(16, 0);
        string low = to_string(start - 1), high = to_string(finish);
        for(int i = s.length(); i < high.length(); i++){
            cnt[i] = i == s.size() ? 1 : cnt[i - 1] * (limit + 1);
        }
        return cnt[high.length() - 1] + dfs(cnt, 0, limit, high, s) - (cnt[low.length() - 1] + dfs(cnt, 0, limit, low, s));
    }
};