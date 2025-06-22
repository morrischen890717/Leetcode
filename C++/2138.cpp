class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int len = s.length();
        vector<string> ans;
        int i = 0;
        for(; i + k <= len; i += k){
            ans.push_back(s.substr(i, k));
        }
        if(len % k){
            string last = s.substr(i);
            while(last.length() < k){
                last += fill;
            }
            ans.push_back(last);
        }
        return ans;
    }
};