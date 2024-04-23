class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        vector<int> farest(26, -1);
        int len = s.length();
        for(int i = 0; i < len; i++){
            farest[s[i] - 'a'] = i;
        }
        int start = -1, end = -1;
        for(int i = 0; i < len; i++){
            end = max(end, farest[s[i] - 'a']);
            if(i == end){
                ans.push_back(i - start);
                start = i;
            }
        }
        return ans;
    }
};