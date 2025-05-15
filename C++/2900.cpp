class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans;
        int n = words.size();
        int group = -1;
        for(int i = 0; i < n; i++){
            if(groups[i] != group)
                ans.push_back(words[i]);
                group = groups[i];
        }
        return ans;
    }
};