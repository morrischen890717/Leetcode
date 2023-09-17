class Solution {
public:
    int longestStrChain(vector<string>& words) {
        // using unordered_map, self-defined sort(), and bottom-up DP
        int ans = 0;
        int n = words.size();
        unordered_map<string, int> m;
        sort(words.begin(), words.end(), [&](string word1, string word2){
            return word1.length() < word2.length();
        }); // sort by the length of each word
        for(string& word: words){
            m[word] = 1;
            for(int i = 0; i < word.length(); i++){
                string predecessor = word.substr(0, i) + word.substr(i + 1);
                if(m.count(predecessor))
                    m[word] = max(m[word], m[predecessor] + 1);
            }
            ans = max(ans, m[word]);
        }
        return ans;
    }
};