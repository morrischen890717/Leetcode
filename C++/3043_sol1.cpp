class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> s;
        for(int num: arr1){
            string ss = to_string(num);
            string prefix;
            for(char c: ss){
                prefix += c;
                s.insert(prefix);
            }
        }
        int ans = 0;
        for(int num: arr2){
            string ss = to_string(num);
            string prefix;
            for(char c: ss){
                prefix += c;
                if(prefix.length() > ans && s.count(prefix))
                    ans = prefix.length();
            }
        }
        return ans;
    }
};