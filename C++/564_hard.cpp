class Solution {
public:
    string nearestPalindromic(string n) {
        // reference: https://leetcode.com/problems/find-the-closest-palindrome/solutions/102391/python-simple-with-explanation/?envType=daily-question&envId=2024-08-24 
        int len = n.length();
        if(len == 1)
            return to_string(stoi(n) - 1);
        int half_len = (len + 1) / 2;
        int half_val = stoi(n.substr(0, half_len));
        vector<long long> candidates;
        candidates.push_back(pow(10, len) + 1);
        candidates.push_back(pow(10, len - 1) - 1);
        for(int i = -1; i <= 1; i++){
            string suffix = to_string(half_val + i);
            if(len % 2)
                suffix.pop_back();
            reverse(suffix.begin(), suffix.end());
            candidates.push_back(stoll(to_string(half_val + i) + suffix));
        }
        string ans;
        int min_diff = INT_MAX;
        sort(candidates.begin(), candidates.end());
        for(long long num: candidates){
            long long diff = abs(num - stoll(n));
            if(num != stoll(n) && diff < min_diff){
                min_diff = diff;
                ans = to_string(num);
            }
        }
        return ans;
    }
};