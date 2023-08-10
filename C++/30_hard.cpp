class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        // using two-pointers and sliding window
        // reference: https://leetcode.com/problems/substring-with-concatenation-of-all-words/solutions/373766/c-solution-32ms-based-on-sliding-window/
        vector<int> ans;
        int len = s.length(), n = words.size(), wordLen = words[0].length();
        unordered_map<string, int> tmp;
        for(string& word: words){
            tmp[word]++;
        }
        for(int i = 0; i < wordLen; i++){
            unordered_map<string, int> cnt;
            int left = i;
            for(int j = i; j < len - wordLen + 1; j += wordLen){
                string ss = s.substr(j, wordLen);
                if(tmp.count(ss) > 0){
                    cnt[ss]++;
                    while(cnt[ss] > tmp[ss]){
                        cnt[s.substr(left, wordLen)]--;
                        left += wordLen;
                    }
                }
                else{
                    cnt.clear();
                    left = j + wordLen;
                }
                if((j - left) / wordLen + 1 == n)
                    ans.push_back(left);
            }
        }
        return ans;
    }
};