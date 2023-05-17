class Solution {
public:
    bool isAnagram(vector<int>& s_cnt, vector<int>& p_cnt){
        for(int i = 0; i < 26; i++){
            if(s_cnt[i] != p_cnt[i])
                return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int len_s = s.length(), len_p = p.length();
        if(len_s < len_p)
            return {};
        vector<int> p_cnt(26, 0);
        vector<int> s_cnt(26, 0);
        vector<int> ans;
        for(int i = 0; i < len_p; i++){
            p_cnt[p[i] - 'a']++;
            s_cnt[s[i] - 'a']++;
        }
        if(isAnagram(s_cnt, p_cnt))
            ans.push_back(0);
        for(int i = 1; i < len_s - len_p + 1; i++){
            s_cnt[s[i - 1] - 'a']--;
            s_cnt[s[i + len_p - 1] - 'a']++;
            if(isAnagram(s_cnt, p_cnt))
                ans.push_back(i);
        }
        return ans;
    }
};