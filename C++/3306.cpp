class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        long long ans = 0;
        int len = word.length();
        unordered_map<char, int> m;
        m['a'] = 0, m['e'] = 1, m['i'] = 2, m['o'] = 3, m['u'] = 4;
        vector<int> last(5, -1);
        int ptr = -1;
        deque<int> consonant;
        for(int r = 0; r < len; r++){
            if(m.count(word[r]))
                last[m[word[r]]] = r;
            else{
                consonant.push_back(r);
                while(consonant.size() > k){
                    ptr = consonant.front();
                    consonant.pop_front();
                }
            }
            int min_id = INT_MAX;
            for(int id: last){
                min_id = min(min_id, id);
            }
            if(min_id > ptr && consonant.size() == k)
                ans += min(min_id, consonant.empty() ? r : consonant.front()) - ptr;
        }
        return ans;
    }
};