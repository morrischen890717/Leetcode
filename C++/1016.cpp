class Solution {
public:
    bool queryString(string s, int n) {
        // time complexity: O(S^2), where S == s.length()
        int len = s.length();
        unordered_set<int> ss;
        ss.insert(0);
        for(int i = 0; i < len; i++){
            int num = 0;
            for(int j = i; j < len && num < n; j++){
                num = num * 2 + (s[j] - '0');
                if(num <= n)
                    ss.insert(num);
            }
        }
        return ss.size() == n + 1;
    }
};