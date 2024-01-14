class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length() != word2.length())
            return false;
        int len = word1.length();
        vector<int> cnt1(26, 0), cnt2(26, 0);
        for(int i = 0; i < len; i++){
            cnt1[word1[i] - 'a']++;
            cnt2[word2[i] - 'a']++;
        }
        unordered_map<int, int> m;
        for(int i = 0; i < cnt1.size(); i++){
            if(cnt1[i] == 0 && cnt2[i] != 0 || cnt1[i] != 0 && cnt2[i] == 0)
                return false;
            m[cnt1[i]]++;
            m[cnt2[i]]--;
        }
        for(unordered_map<int, int>::iterator it = m.begin(); it != m.end(); it++){
            if(it->second != 0)
                return false;
        }
        return true;
    }
};